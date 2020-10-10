#include "DuplicatesFinderActions.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"

std::shared_ptr<Action> DuplicatesFinderActions::findDuplicatesAction() {
    Payload payload;

    return std::make_shared<Action>(DuplicatesFinderActionTypes::STORE_MARK,
                                    DuplicatesFinderActionTypes::FIND_DUPLICATES);
}
