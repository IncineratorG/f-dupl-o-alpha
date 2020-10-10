#ifndef INPUTFOLDERSLISTREDUCER_H
#define INPUTFOLDERSLISTREDUCER_H

#include "common/libs/redux/reducer/Reducer.h"

class InputFoldersListReducer : public Reducer
{
public:
    InputFoldersListReducer();

    void reduce(std::shared_ptr<State> state,
                std::shared_ptr<Action> action);
};

#endif // INPUTFOLDERSLISTREDUCER_H
