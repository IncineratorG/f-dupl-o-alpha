#ifndef STORE_H
#define STORE_H

#include "common/libs/redux/reducer/Reducer.h"
#include "common/libs/redux/state/State.h"

#include <memory>

class Store
{
public:
    Store(std::shared_ptr<Reducer> reducer, std::shared_ptr<State> state);

    std::shared_ptr<State> state() const;

    void dispatch(const std::shared_ptr<Action> action);

private:
    std::shared_ptr<Reducer> mReducer;
    std::shared_ptr<State> mState;
};

#endif // STORE_H
