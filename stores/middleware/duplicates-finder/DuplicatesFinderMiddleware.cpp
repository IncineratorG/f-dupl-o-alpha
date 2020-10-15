#include "DuplicatesFinderMiddleware.h"
#include "stores/AppStore.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"
#include "stores/actions/duplicates-finder/DuplicatesFinderActions.h"
#include "services/Services.h"
#include "services/duplicates-finder/data/input-path/InputPath.h"

#include <QDebug>

DuplicatesFinderMiddleware::DuplicatesFinderMiddleware() {

}

void DuplicatesFinderMiddleware::onAction(std::shared_ptr<Action> action) {
    if (action->storeMark() != DuplicatesFinderActionTypes::STORE_MARK) {
        return;
    }

    switch (action->type()) {
        case (DuplicatesFinderActionTypes::FIND_DUPLICATES): {
            try {
                AppStore::get()->dispatch(
                    DuplicatesFinderActions::findDuplicatesBeginAction()
                );

                auto inputPaths = std::any_cast<QList<InputPath>>(action->payload().get("inputPaths"));
                Services::get()->duplicatesFinderService->start(inputPaths);
            } catch (const std::bad_any_cast& e) {
                qDebug() << __PRETTY_FUNCTION__ << "->FIND_DUPLICATES->BAD_ANY_CAST: " + QString(e.what());

                AppStore::get()->dispatch(
                    DuplicatesFinderActions::findDuplicatesErrorAction(Error(1, "BAD_ANY_CAST_IN_MIDDLEWARE"))
                );
            }
            break;
        }

        default: {

        }
    }
}
