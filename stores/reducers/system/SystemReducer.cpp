#include "SystemReducer.h"
#include "stores/states/system/SystemState.h"
#include "stores/action-types/system/SystemActionTypes.h"

SystemReducer::SystemReducer() {

}

void SystemReducer::reduce(std::shared_ptr<State> state,
                         std::shared_ptr<Action> action) {
//    if (action->storeMark() != SystemActionTypes::STORE_MARK) {
//        return;
//    }

//    auto currentState = std::dynamic_pointer_cast<SystemState>(state);
}
