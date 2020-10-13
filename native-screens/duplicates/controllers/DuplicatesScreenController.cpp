#include "DuplicatesScreenController.h"
#include "stores/AppStore.h"
#include "stores/actions/input-folders-list/InputFoldersListActions.h"
#include "stores/actions/duplicates-finder/DuplicatesFinderActions.h"

#include <QList>
#include <QString>
#include <QDebug>

DuplicatesScreenController::DuplicatesScreenController() {

}

void DuplicatesScreenController::addFolderHandler(const QString& folderUrl) {
    QString validFolderUrl = folderUrl;

    const QString qmlFilePrefix = AppStore::get()->systemState->qmlFilePrefix->value();
    if (validFolderUrl.contains(qmlFilePrefix)) {
        validFolderUrl.remove(0, qmlFilePrefix.length());
    }

    AppStore::get()->dispatch(
        InputFoldersListActions::addFolderAction(validFolderUrl)
    );
}

void DuplicatesScreenController::removeFolderButtonHandler(const QString& folderName) {
    AppStore::get()->dispatch(
        InputFoldersListActions::removeFolderAction(folderName)
    );
}

void DuplicatesScreenController::startScanningButtonHandler() {
    qDebug() << __PRETTY_FUNCTION__;

    const QList<InputPath>& inputPaths = AppStore::get()->inputFoldersListState->inputFolders->value();
    if (inputPaths.length() <= 0) {
        return;
    }

    AppStore::get()->dispatch(
        DuplicatesFinderActions::findDuplicatesAction(inputPaths)
    );

//    auto inputFoldersListState = AppStore::get()->inputFoldersListState;
//    auto inputFolderNamesList = inputFoldersListState->folderNames->get();
//    for (int i = 0; i < inputFolderNamesList.length(); ++i) {
//        qDebug() << __PRETTY_FUNCTION__ << inputFolderNamesList.at(i);
//    }
}

void DuplicatesScreenController::setIncludeFolderSubpaths(const QString& folderName,
                                                          const bool includeSubpath) {
    AppStore::get()->dispatch(
        InputFoldersListActions::updateFolderAction(folderName, includeSubpath)
    );
}
