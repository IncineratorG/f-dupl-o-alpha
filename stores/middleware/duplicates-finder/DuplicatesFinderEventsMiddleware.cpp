#include "DuplicatesFinderEventsMiddleware.h"
#include "services/Services.h"
#include "services/duplicates-finder/event-types/DuplicatesFinderServiceEventTypes.h"
#include "services/duplicates-finder/data/duplicates-list/DuplicatesList.h"
#include "stores/AppStore.h"
#include "stores/actions/duplicates-finder/DuplicatesFinderActions.h"

#include <QDebug>

DuplicatesFinderEventsMiddleware::DuplicatesFinderEventsMiddleware() {

}

void DuplicatesFinderEventsMiddleware::init() {
    std::function<void(std::any)> serviceStartedHandler = [] (std::any) {
        qDebug() << __PRETTY_FUNCTION__ << "->SERVICE_STARTED_HANDLER";
    };

    std::function<void(std::any)> servicePausedHandler = [] (std::any) {
        qDebug() << __PRETTY_FUNCTION__ << "->SERVICE_PAUSED_HANDLER";
    };

    std::function<void(std::any)> serviceStoppedHandler = [] (std::any) {
        qDebug() << __PRETTY_FUNCTION__ << "->SERVICE_STOPPED_HANDLER";
    };

    std::function<void(std::any)> serviceFinishedHandler = [] (std::any data) {
        qDebug() << __PRETTY_FUNCTION__ << "->SERVICE_FINISHED_HANDLER";        
        try {
            auto duplicates = std::any_cast<DuplicatesList>(data);
            AppStore::get()->dispatch(
                DuplicatesFinderActions::findDuplicatesFinishedAction(duplicates)
            );
        } catch (const std::bad_any_cast&) {
            qDebug() << __PRETTY_FUNCTION__ << "->FIND_DUPLICATES_FINISHED->BAD_ANY_CAST";
        }
    };

    auto duplicatesFinderService = Services::get()->duplicatesFinderService;

    duplicatesFinderService->subscribe(
        DuplicatesFinderServiceEventTypes::SERVICE_STARTED,
        serviceStartedHandler
    );

    duplicatesFinderService->subscribe(
        DuplicatesFinderServiceEventTypes::SERVICE_PAUSED,
        servicePausedHandler
    );

    duplicatesFinderService->subscribe(
        DuplicatesFinderServiceEventTypes::SERVICE_STOPPED,
        serviceStoppedHandler
    );

    duplicatesFinderService->subscribe(
        DuplicatesFinderServiceEventTypes::SERVICE_FINISHED,
        serviceFinishedHandler
    );
}
