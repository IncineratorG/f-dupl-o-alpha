#ifndef SYSTEMREDUCER_H
#define SYSTEMREDUCER_H

#include "common/libs/redux/reducer/Reducer.h"

class SystemReducer : public Reducer
{
public:
    SystemReducer();

    void reduce(std::shared_ptr<State> state,
                std::shared_ptr<Action> action);
};

#endif // SYSTEMREDUCER_H
