#include "InputFoldersController.h"
#include "stores/AppStore.h"
#include "stores/actions/input-folders-list/InputFoldersListActions.h"

InputFoldersController::InputFoldersController() {

}

void InputFoldersController::addFolderHandler(const QString& folderUrl) {
    QString validFolderUrl = folderUrl;

    const QString qmlFilePrefix = AppStore::get()->systemState->qmlFilePrefix->value();
    if (validFolderUrl.contains(qmlFilePrefix)) {
        validFolderUrl.remove(0, qmlFilePrefix.length());
    }

    AppStore::get()->dispatch(
        InputFoldersListActions::addFolderAction(validFolderUrl)
    );
}

void InputFoldersController::removeFolderButtonHandler(const QString& folderName) {
    AppStore::get()->dispatch(
        InputFoldersListActions::removeFolderAction(folderName)
    );
}

void InputFoldersController::setIncludeFolderSubpaths(const QString& folderName,
                                                          const bool includeSubpath) {
    AppStore::get()->dispatch(
        InputFoldersListActions::updateFolderAction(folderName, includeSubpath)
    );
}
