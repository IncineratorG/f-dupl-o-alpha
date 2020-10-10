#ifndef DUPLICATESFINDERREDUCER_H
#define DUPLICATESFINDERREDUCER_H

#include "common/libs/redux/reducer/Reducer.h"

class DuplicatesFinderReducer : public Reducer
{
public:
    DuplicatesFinderReducer();

    void reduce(std::shared_ptr<State> state,
                std::shared_ptr<Action> action);
};

#endif // DUPLICATESFINDERREDUCER_H
