#include "InputFoldersListReducer.h"
#include "stores/action-types/input-folders-list/InputFoldersListActionTypes.h"
#include "stores/states/input-folders-list/InputFoldersListState.h"

#include <QDebug>

InputFoldersListReducer::InputFoldersListReducer() {

}

void InputFoldersListReducer::reduce(std::shared_ptr<State> state,
                         std::shared_ptr<Action> action) {
    if (action->storeMark() != InputFoldersListActionTypes::STORE_MARK) {
        return;
    }

    auto currentState = std::dynamic_pointer_cast<InputFoldersListState>(state);

    switch (action->type()) {
        case (InputFoldersListActionTypes::ADD_FOLDER_NAME): {
            try {
                auto folderName = std::any_cast<QString>(action->payload().getDefault());

                currentState->update([currentState, folderName] () {
                    auto folderNames = currentState->folderNames->get();
                    folderNames.append(folderName);
                    currentState->folderNames->set(folderNames);
                });
            } catch (const std::bad_any_cast& e) {
                qDebug() << __PRETTY_FUNCTION__ << "->ADD_FOLDER_NAME->BAD_ANY_CAST";
            }

            break;
        }

        default: {

        }
    }
}
