#ifndef TESTACTIONS_H
#define TESTACTIONS_H

#include "common/libs/redux/action/Action.h"

#include <memory>

class TestActions
{
public:
    static std::shared_ptr<Action> firstTestAction();
};

#endif // TESTACTIONS_H
