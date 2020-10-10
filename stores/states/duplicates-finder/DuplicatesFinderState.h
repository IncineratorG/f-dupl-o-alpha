#ifndef DUPLICATESFINDERSTATE_H
#define DUPLICATESFINDERSTATE_H

#include "common/libs/redux/state/State.h"
#include "common/libs/redux/prop/StatePropLike.h"
#include "common/libs/redux/prop/StateProp.h"

class DuplicatesFinderState : public State
{
public:
    DuplicatesFinderState();

protected:
    QList<std::shared_ptr<StatePropLike> > stateProps() const;
};

#endif // DUPLICATESFINDERSTATE_H
