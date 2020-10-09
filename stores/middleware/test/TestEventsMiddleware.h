#ifndef TESTEVENTSMIDDLEWARE_H
#define TESTEVENTSMIDDLEWARE_H

#include "common/libs/redux/middleware/EventsMiddleware.h"

class TestEventsMiddleware : public EventsMiddleware
{
public:
    TestEventsMiddleware();

    void init();
};

#endif // TESTEVENTSMIDDLEWARE_H
