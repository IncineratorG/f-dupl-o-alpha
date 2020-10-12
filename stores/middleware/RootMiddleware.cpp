#include "RootMiddleware.h"
#include "stores/middleware/test/TestMiddleware.h"
#include "stores/middleware/test/TestEventsMiddleware.h"
#include "stores/middleware/duplicates-finder/DuplicatesFinderMiddleware.h"
#include "stores/middleware/duplicates-finder/DuplicatesFinderEventsMiddleware.h"

RootMiddleware::RootMiddleware() {
    mMiddlewares.append({
        std::make_shared<TestMiddleware>(),
        std::make_shared<DuplicatesFinderMiddleware>()
    });


    mEventsMiddlewares.append({
        std::make_shared<TestEventsMiddleware>(),
        std::make_shared<DuplicatesFinderEventsMiddleware>()
    });

    for (int i = 0; i < mEventsMiddlewares.length(); ++i) {
        mEventsMiddlewares.at(i)->init();
    }
}

void RootMiddleware::onAction(std::shared_ptr<Action> action) {
    for (int i = 0; i < mMiddlewares.length(); ++i) {
        mMiddlewares.at(i)->onAction(action);
    }
}
