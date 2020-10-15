#ifndef DUPLICATESFINDERSTATE_H
#define DUPLICATESFINDERSTATE_H

#include "common/libs/redux/state/State.h"
#include "common/libs/redux/prop/StatePropLike.h"
#include "common/libs/redux/prop/StateProp.h"
#include "services/duplicates-finder/data/duplicates-list/DuplicatesList.h"

class DuplicatesFinderState : public State
{
public:
    std::shared_ptr<StateProp<DuplicatesList>> duplicates;
    std::shared_ptr<StateProp<bool>> serviceRunning;

    DuplicatesFinderState();

protected:
    QList<std::shared_ptr<StatePropLike> > stateProps() const;
};

#endif // DUPLICATESFINDERSTATE_H
