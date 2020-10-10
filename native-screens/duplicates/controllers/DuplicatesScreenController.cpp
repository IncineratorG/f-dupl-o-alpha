#include "DuplicatesScreenController.h"
#include "stores/AppStore.h"
#include "stores/actions/input-folders-list/InputFoldersListActions.h"

#include <QList>
#include <QString>
#include <QDebug>

DuplicatesScreenController::DuplicatesScreenController() {

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

void DuplicatesScreenController::removeFolderButtonHandler(const QString& folderName) {
    AppStore::get()->dispatch(
        InputFoldersListActions::removeFolderNameAction(folderName)
    );
}

void DuplicatesScreenController::startScanningButtonHandler() {
    qDebug() << __PRETTY_FUNCTION__;

    auto inputFoldersListState = AppStore::get()->inputFoldersListState;
    auto inputFolderNamesList = inputFoldersListState->folderNames->get();
    for (int i = 0; i < inputFolderNamesList.length(); ++i) {
        qDebug() << __PRETTY_FUNCTION__ << inputFolderNamesList.at(i);
    }
}
