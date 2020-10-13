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
        case (InputFoldersListActionTypes::ADD_FOLDER): {
            try {
                auto folderName = std::any_cast<QString>(action->payload().get("folderName"));
                auto includeSubpath = std::any_cast<bool>(action->payload().get("includeSubpath"));

                currentState->update([currentState, folderName, includeSubpath] () {
                    auto inputFolders = currentState->inputFolders->value();
                    for (int i = 0; i < inputFolders.length(); ++i) {
                        if (inputFolders.at(i).path() == folderName) {
                            return;
                        }
                    }

                    inputFolders.append(InputPath(folderName, includeSubpath));
                    currentState->inputFolders->set(inputFolders);
                });
            } catch (const std::bad_any_cast& e) {
                qDebug() << __PRETTY_FUNCTION__ << "->ADD_FOLDER->BAD_ANY_CAST";
            }

            break;
        }

        case (InputFoldersListActionTypes::REMOVE_FOLDER): {
            try {
                auto folderName = std::any_cast<QString>(action->payload().getDefault());

                currentState->update([currentState, folderName] () {
                    auto inputFolders = currentState->inputFolders->value();
                    for (int i = 0; i < inputFolders.length(); ++i) {
                        if (inputFolders.at(i).path() == folderName) {
                            inputFolders.removeAt(i);
                            break;
                        }
                    }

                    currentState->inputFolders->set(inputFolders);
                });
            } catch (const std::bad_any_cast& e) {
                qDebug() << __PRETTY_FUNCTION__ << "->REMOVE_FOLDER->BAD_ANY_CAST";
            }


            break;
        }

        case (InputFoldersListActionTypes::UPDATE_FOLDER): {
            try {
                auto folderName = std::any_cast<QString>(action->payload().get("folderName"));
                auto includeSubpath = std::any_cast<bool>(action->payload().get("includeSubpath"));

                currentState->update([currentState, folderName, includeSubpath] () {
                    auto inputFolders = currentState->inputFolders->value();
                    for (int i = 0; i < inputFolders.length(); ++i) {
                        if (inputFolders.at(i).path() == folderName) {
                            inputFolders.replace(i, InputPath(folderName, includeSubpath));
                            break;
                        }
                    }

                    currentState->inputFolders->set(inputFolders);
                });
            } catch (const std::bad_any_cast& e) {
                qDebug() << __PRETTY_FUNCTION__ << "->UPDATE_FOLDER->BAD_ANY_CAST";
            }

            break;
        }

        default: {

        }
    }
}
