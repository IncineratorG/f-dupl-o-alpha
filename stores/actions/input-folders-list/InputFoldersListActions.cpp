#include "InputFoldersListActions.h"
#include "stores/action-types/input-folders-list/InputFoldersListActionTypes.h"

std::shared_ptr<Action> InputFoldersListActions::addFolderNameAction(const QString& folderName) {
    Payload payload(folderName);

    return std::make_shared<Action>(InputFoldersListActionTypes::STORE_MARK,
                                    InputFoldersListActionTypes::ADD_FOLDER_NAME,
                                    payload);
}
