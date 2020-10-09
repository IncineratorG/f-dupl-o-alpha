#ifndef TESTSTATE_H
#define TESTSTATE_H

#include "common/libs/redux/state/State.h"
#include "common/libs/redux/prop/StatePropLike.h"
#include "common/libs/redux/prop/StateProp.h"

#include <memory>

class TestState : public State
{
public:
    std::shared_ptr<StateProp<int>> prop1;
    std::shared_ptr<StateProp<int>> prop2;
    std::shared_ptr<StateProp<int>> prop3;

    TestState();

protected:
    QList<std::shared_ptr<StatePropLike> > stateProps() const;
};

#endif // TESTSTATE_H
