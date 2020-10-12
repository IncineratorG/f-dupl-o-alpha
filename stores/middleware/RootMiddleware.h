#ifndef ROOTMIDDLEWARE_H
#define ROOTMIDDLEWARE_H

#include "common/libs/redux/middleware/Middleware.h"
#include "common/libs/redux/middleware/EventsMiddleware.h"

#include <QList>

class RootMiddleware : public Middleware
{
public:
    RootMiddleware();

    void onAction(std::shared_ptr<Action> action);

private:
    QList<std::shared_ptr<Middleware>> mMiddlewares;
    QList<std::shared_ptr<EventsMiddleware>> mEventsMiddlewares;
};

#endif // ROOTMIDDLEWARE_H
