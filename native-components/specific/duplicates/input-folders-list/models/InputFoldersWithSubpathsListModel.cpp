#include "InputFoldersWithSubpathsListModel.h"
#include "stores/AppStore.h"

InputFoldersWithSubpathsListModel::InputFoldersWithSubpathsListModel() {
    auto inputFoldersListState = AppStore::get()->inputFoldersListState;
    inputFoldersListState->select(
        Selector(
            {inputFoldersListState->inputFolders},
            [this, inputFoldersListState] () {
                beginResetModel();
                mPaths = inputFoldersListState->inputFolders->value();
                endResetModel();

                emit sizeChanged(mPaths.length());
            }
        )
    );
}

int InputFoldersWithSubpathsListModel::rowCount(const QModelIndex& parent) const {
    return mPaths.length();
}

QVariant InputFoldersWithSubpathsListModel::data(const QModelIndex& index, int role) const {
    if (index.row() < 0 || index.row() >= mPaths.length()) {
        return QVariant();
    }

    switch (role) {
        case IDRole: {
            return index.row();
        }

        case FolderNameRole: {
            return mPaths.at(index.row()).path();
        }

        case IncludeSubpathRole: {
            return mPaths.at(index.row()).includeSubpath();
        }
    }

    return QVariant();
}

QHash<int, QByteArray> InputFoldersWithSubpathsListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "id";
    roles[FolderNameRole] = "folderName";
    roles[IncludeSubpathRole] = "includeSubpath";

    return roles;
}

int InputFoldersWithSubpathsListModel::size() const {
    return mPaths.length();
}
