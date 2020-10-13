#include "InputFoldersListActions.h"
#include "stores/action-types/input-folders-list/InputFoldersListActionTypes.h"

std::shared_ptr<Action> InputFoldersListActions::addFolderAction(const QString& folderName,
                                                                     const bool includeSubpath) {
    Payload payload;
    payload.set("folderName", folderName);
    payload.set("includeSubpath", includeSubpath);

    return std::make_shared<Action>(InputFoldersListActionTypes::STORE_MARK,
                                    InputFoldersListActionTypes::ADD_FOLDER,
                                    payload);
}

std::shared_ptr<Action> InputFoldersListActions::removeFolderAction(const QString& folderName) {
    Payload payload(folderName);

    return std::make_shared<Action>(InputFoldersListActionTypes::STORE_MARK,
                                    InputFoldersListActionTypes::REMOVE_FOLDER,
                                    payload);
}

std::shared_ptr<Action> InputFoldersListActions::updateFolderAction(const QString& folderName,
                                                                    const bool includeSubpath) {
    Payload payload;
    payload.set("folderName", folderName);
    payload.set("includeSubpath", includeSubpath);

    return std::make_shared<Action>(InputFoldersListActionTypes::STORE_MARK,
                                    InputFoldersListActionTypes::UPDATE_FOLDER,
                                    payload);
}
