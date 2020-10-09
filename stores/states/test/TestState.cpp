#include "TestState.h"

TestState::TestState() {
    prop1 = std::make_shared<StateProp<int>>(0);
    prop2 = std::make_shared<StateProp<int>>(0);
    prop3 = std::make_shared<StateProp<int>>(0);

    initState();
}

QList<std::shared_ptr<StatePropLike>> TestState::stateProps() const {
    QList<std::shared_ptr<StatePropLike>> props({
                                                    prop1,
                                                    prop2,
                                                    prop3
                                                });

    return props;
}
