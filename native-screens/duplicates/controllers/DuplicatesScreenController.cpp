#include "DuplicatesScreenController.h"
#include "stores/AppStore.h"
#include "stores/actions/input-folders-list/InputFoldersListActions.h"

#include <QList>
#include <QString>
#include <QDebug>

DuplicatesScreenController::DuplicatesScreenController() {
//    AppStore::get()->inputFoldersListState->select(Selector({}, [] () {

//    }));

    auto inputFoldersListState = AppStore::get()->inputFoldersListState;

    inputFoldersListState->select(
                Selector(
                    {inputFoldersListState->folderNames->propId()},
                    [inputFoldersListState] () {
//                        QList<QString> folderNames = inputFoldersListState->folderNames->get();

//                        qDebug() << __PRETTY_FUNCTION__ << "->SIZE: " << folderNames.length();

//                        for (int i = 0; i < folderNames.length(); ++i) {
//                            qDebug() << __PRETTY_FUNCTION__ << folderNames.at(i);
//                        }
                    })
                );
}

void DuplicatesScreenController::addFolderHandler(const QString& folderUrl) {
    QString validFolderUrl = folderUrl;

    const QString qmlFilePrefix = AppStore::get()->systemState->qmlFilePrefix->get();
    if (validFolderUrl.contains(qmlFilePrefix)) {
        validFolderUrl.remove(0, qmlFilePrefix.length());
    }

    AppStore::get()->dispatch(
                    InputFoldersListActions::addFolderNameAction(validFolderUrl)
                );
}

void DuplicatesScreenController::removeFolderButtonHandler() {
    qDebug() << __PRETTY_FUNCTION__;
}
