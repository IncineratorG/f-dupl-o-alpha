#ifndef TESTMIDDLEWARE_H
#define TESTMIDDLEWARE_H

#include "common/libs/redux/middleware/Middleware.h"

class TestMiddleware : public Middleware
{
public:
    TestMiddleware();

    void onAction(std::shared_ptr<Action> action);
};

#endif // TESTMIDDLEWARE_H
