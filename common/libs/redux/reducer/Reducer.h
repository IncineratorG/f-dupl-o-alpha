#ifndef REDUCER_H
#define REDUCER_H

#include "common/libs/redux/action/Action.h"
#include "common/libs/redux/state/State.h"

#include <memory>

class Reducer
{
public:
    virtual ~Reducer() = 0;

    virtual void reduce(std::shared_ptr<State> state,
                        std::shared_ptr<Action> action) = 0;
};

#endif // REDUCER_H
