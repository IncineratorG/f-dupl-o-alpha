#include "DuplicatesFinderMiddleware.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"

DuplicatesFinderMiddleware::DuplicatesFinderMiddleware() {

}

void DuplicatesFinderMiddleware::onAction(std::shared_ptr<Action> action) {
    if (action->storeMark() != DuplicatesFinderActionTypes::STORE_MARK) {
        return;
    }

    switch (action->type()) {
        case (DuplicatesFinderActionTypes::FIND_DUPLICATES): {
            break;
        }

        default: {

        }
    }
}
