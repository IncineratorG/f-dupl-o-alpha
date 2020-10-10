#ifndef DUPLICATESFINDERACTIONS_H
#define DUPLICATESFINDERACTIONS_H

#include "common/libs/redux/action/Action.h"

#include <memory>

class DuplicatesFinderActions
{
public:
    static std::shared_ptr<Action> findDuplicatesAction();
};

#endif // DUPLICATESFINDERACTIONS_H
