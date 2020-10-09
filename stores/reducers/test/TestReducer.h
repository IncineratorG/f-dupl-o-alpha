#ifndef TESTREDUCER_H
#define TESTREDUCER_H

#include "common/libs/redux/reducer/Reducer.h"

class TestReducer : public Reducer
{
public:
    TestReducer();

    void reduce(std::shared_ptr<State> state,
                std::shared_ptr<Action> action);
};

#endif // TESTREDUCER_H
