#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H

#include "common/libs/redux/state/State.h"
#include "common/libs/redux/prop/StatePropLike.h"
#include "common/libs/redux/prop/StateProp.h"

#include <QString>

class SystemState : public State
{
public:
    std::shared_ptr<StateProp<QString>> qmlFilePrefix;

    SystemState();

protected:
    QList<std::shared_ptr<StatePropLike> > stateProps() const;
};

#endif // SYSTEMSTATE_H
