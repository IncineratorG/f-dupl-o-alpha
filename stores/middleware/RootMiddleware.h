#ifndef ROOTMIDDLEWARE_H
#define ROOTMIDDLEWARE_H

#include "common/libs/redux/middleware/Middleware.h"

#include "stores/middleware/test/TestMiddleware.h"
#include "stores/middleware/test/TestEventsMiddleware.h"

#include <QList>

class RootMiddleware : public Middleware
{
public:
    RootMiddleware();

    void onAction(std::shared_ptr<Action> action);

private:
    QList<std::shared_ptr<Middleware>> mMiddlewares;
    QList<std::shared_ptr<EventsMiddleware>> mEventsMiddlewares;

    std::shared_ptr<Middleware> mTestMiddleware;
    std::shared_ptr<EventsMiddleware> mTestEventsMiddleware;
};

#endif // ROOTMIDDLEWARE_H