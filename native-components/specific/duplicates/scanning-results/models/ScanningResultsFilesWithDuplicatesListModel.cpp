#include "ScanningResultsFilesWithDuplicatesListModel.h"
#include "stores/AppStore.h"

#include <QDebug>

ScanningResultsFilesWithDuplicatesListModel::ScanningResultsFilesWithDuplicatesListModel() {
    auto duplicatesState = AppStore::get()->duplicatesFinderState;
    duplicatesState->select(
        Selector(
            {duplicatesState->duplicates},
            [this, duplicatesState] () {
                auto duplicatesList = duplicatesState->duplicates->value();

                auto filesWithDuplicates = duplicatesList.files();
//                for (int i = 0; i < filesWithDuplicates.length(); ++i) {
//                    qDebug() << filesWithDuplicates.at(i).completeBaseName();
//                }
            }
        )
    );
}

int ScanningResultsFilesWithDuplicatesListModel::rowCount(const QModelIndex& parent) const {
//    return mPaths.length();
    return 0;
}

QVariant ScanningResultsFilesWithDuplicatesListModel::data(const QModelIndex& index, int role) const {
//    if (index.row() < 0 || index.row() >= mPaths.length()) {
//        return QVariant();
//    }

//    switch (role) {
//        case IDRole: {
//            return index.row();
//        }

//        case FolderNameRole: {
//            return mPaths.at(index.row()).path();
//        }

//        case IncludeSubpathRole: {
//            return mPaths.at(index.row()).includeSubpath();
//        }
//    }

    return QVariant();
}

QHash<int, QByteArray> ScanningResultsFilesWithDuplicatesListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "id";
    roles[FileNameRole] = "fileName";

    return roles;
}
