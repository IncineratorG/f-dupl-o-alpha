#include "TestActions.h"
#include "stores/action-types/test/TestActionTypes.h"

std::shared_ptr<Action> TestActions::firstTestAction() {
    return std::make_shared<Action>(TestActionTypes::STORE_MARK, TestActionTypes::FIRST_TEST);
}
