#include "InputFoldersListReducer.h"
#include "stores/action-types/input-folders-list/InputFoldersListActionTypes.h"
#include "stores/states/input-folders-list/InputFoldersListState.h"

InputFoldersListReducer::InputFoldersListReducer() {

}

void InputFoldersListReducer::reduce(std::shared_ptr<State> state,
                         std::shared_ptr<Action> action) {
    if (action->storeMark() != InputFoldersListActionTypes::STORE_MARK) {
        return;
    }

    auto currentState = std::dynamic_pointer_cast<InputFoldersListState>(state);

    switch (action->type()) {
//        case (TestActionTypes::FIRST_TEST): {
//            qDebug() << __PRETTY_FUNCTION__;

//            testState->update([testState] (){
//                testState->prop1->set(3);
//            });

//            break;
//        }

//        default: {

//        }
    }
}
