#include "DuplicatesFinderMiddleware.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"
#include "services/Services.h"

DuplicatesFinderMiddleware::DuplicatesFinderMiddleware() {

}

void DuplicatesFinderMiddleware::onAction(std::shared_ptr<Action> action) {
    if (action->storeMark() != DuplicatesFinderActionTypes::STORE_MARK) {
        return;
    }

    switch (action->type()) {
        case (DuplicatesFinderActionTypes::FIND_DUPLICATES): {
            auto duplicatesFinderService = Services::get()->duplicatesFinderService;
            duplicatesFinderService->start();
            break;
        }

        default: {

        }
    }
}
