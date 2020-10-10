#ifndef DUPLICATESFINDERACTIONS_H
#define DUPLICATESFINDERACTIONS_H

#include "common/libs/redux/action/Action.h"

#include <memory>

class DuplicatesFinderActions
{
public:
    static std::shared_ptr<Action> findDuplicatesAction();
    static std::shared_ptr<Action> findDuplicatesBeginAction();
    static std::shared_ptr<Action> findDuplicatesFinishedAction();
    static std::shared_ptr<Action> findDuplicatesErrorAction();
};

#endif // DUPLICATESFINDERACTIONS_H
