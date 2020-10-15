#ifndef DUPLICATESFINDERACTIONS_H
#define DUPLICATESFINDERACTIONS_H

#include "common/libs/redux/action/Action.h"
#include "common/data/error/Error.h"
#include "services/duplicates-finder/data/input-path/InputPath.h"
#include "services/duplicates-finder/data/duplicates-list/DuplicatesList.h"

#include <memory>

class DuplicatesFinderActions
{
public:
    static std::shared_ptr<Action> findDuplicatesAction(const QList<InputPath>& inputPaths);
    static std::shared_ptr<Action> findDuplicatesBeginAction();
    static std::shared_ptr<Action> findDuplicatesFinishedAction(const DuplicatesList& duplicates);
    static std::shared_ptr<Action> findDuplicatesErrorAction(const Error& error);
};

#endif // DUPLICATESFINDERACTIONS_H
