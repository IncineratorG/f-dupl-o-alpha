#include "DuplicatesFinderActions.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"

std::shared_ptr<Action> DuplicatesFinderActions::findDuplicatesAction() {
    Payload payload;

    return std::make_shared<Action>(DuplicatesFinderActionTypes::STORE_MARK,
                                    DuplicatesFinderActionTypes::FIND_DUPLICATES);
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
