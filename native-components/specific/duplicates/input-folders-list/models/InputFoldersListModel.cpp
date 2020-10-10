#include "InputFoldersListModel.h"
#include "stores/AppStore.h"

#include <QDebug>

InputFoldersListModel::InputFoldersListModel() {
    auto inputFoldersListState = AppStore::get()->inputFoldersListState;
    inputFoldersListState->select(
        Selector(
            {inputFoldersListState->folderNames},
            [this, inputFoldersListState] () {
                beginResetModel();
                folderNames = inputFoldersListState->folderNames->get();
                endResetModel();
            }
        )
    );
}

int InputFoldersListModel::rowCount(const QModelIndex& parent) const {
    return folderNames.length();
}

QVariant InputFoldersListModel::data(const QModelIndex& index, int role) const {
    if (index.row() < 0 || index.row() >= folderNames.length()) {
        return QVariant();
    }

    switch (role) {
        case IDRole: {
            return index.row();
        }

        case FolderNameRole: {
            return folderNames.at(index.row());
        }
    }

    return QVariant();
}

QHash<int, QByteArray> InputFoldersListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "id";
    roles[FolderNameRole] = "folderName";

    return roles;
}
