#include "TestReducer.h"
#include "stores/action-types/test/TestActionTypes.h"
#include "stores/states/test/TestState.h"

#include <QDebug>

TestReducer::TestReducer() {

}

void TestReducer::reduce(std::shared_ptr<State> state,
                         std::shared_ptr<Action> action) {
    if (action->storeMark() != TestActionTypes::STORE_MARK) {
        return;
    }

    auto testState = std::static_pointer_cast<TestState>(state);

    switch (action->type()) {
        case (TestActionTypes::FIRST_TEST): {
            qDebug() << __PRETTY_FUNCTION__;

            testState->update([testState] (){
                testState->prop1->set(3);
            });

            break;
        }

        default: {

        }
    }
}
