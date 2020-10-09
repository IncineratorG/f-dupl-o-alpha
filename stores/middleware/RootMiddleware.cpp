#include "RootMiddleware.h"

RootMiddleware::RootMiddleware() {
    mTestMiddleware = std::make_shared<TestMiddleware>();

    mMiddlewares.append(
                    mTestMiddleware
                );

    mTestEventsMiddleware = std::make_shared<TestEventsMiddleware>();

    mEventsMiddlewares.append(
                    mTestEventsMiddleware
                );

    for (int i = 0; i < mEventsMiddlewares.length(); ++i) {
        mEventsMiddlewares.at(i)->init();
    }
}

void RootMiddleware::onAction(std::shared_ptr<Action> action) {
    for (int i = 0; i < mMiddlewares.length(); ++i) {
        mMiddlewares.at(i)->onAction(action);
    }
}
