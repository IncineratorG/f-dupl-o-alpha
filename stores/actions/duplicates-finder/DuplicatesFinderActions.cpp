#include "DuplicatesFinderActions.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"

std::shared_ptr<Action> DuplicatesFinderActions::findDuplicatesAction(const QList<InputPath>& inputPaths) {
    Payload payload;
    payload.set("inputPaths", inputPaths);

    return std::make_shared<Action>(DuplicatesFinderActionTypes::STORE_MARK,
                                    DuplicatesFinderActionTypes::FIND_DUPLICATES,
                                    payload);
}

std::shared_ptr<Action> DuplicatesFinderActions::findDuplicatesBeginAction() {
    Payload payload;

    return std::make_shared<Action>(DuplicatesFinderActionTypes::STORE_MARK,
                                    DuplicatesFinderActionTypes::FIND_DUPLICATES_BEGIN);
}

std::shared_ptr<Action> DuplicatesFinderActions::findDuplicatesFinishedAction() {
    Payload payload;

    return std::make_shared<Action>(DuplicatesFinderActionTypes::STORE_MARK,
                                    DuplicatesFinderActionTypes::FIND_DUPLICATES_FINISHED);
}

std::shared_ptr<Action> DuplicatesFinderActions::findDuplicatesErrorAction() {
    Payload payload;

    return std::make_shared<Action>(DuplicatesFinderActionTypes::STORE_MARK,
                                    DuplicatesFinderActionTypes::FIND_DUPLICATES_ERROR);
}
