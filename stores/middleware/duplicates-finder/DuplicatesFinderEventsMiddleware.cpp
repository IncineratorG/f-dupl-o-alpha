#include "DuplicatesFinderEventsMiddleware.h"
#include "services/Services.h"
#include "services/duplicates-finder/event-types/DuplicatesFinderServiceEventTypes.h"

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

    std::function<void(std::any)> serviceFinishedHandler = [] (std::any) {
        qDebug() << __PRETTY_FUNCTION__ << "->SERVICE_FINISHED_HANDLER";
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
