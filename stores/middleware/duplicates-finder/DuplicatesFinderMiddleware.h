#ifndef DUPLICATESFINDERMIDDLEWARE_H
#define DUPLICATESFINDERMIDDLEWARE_H

#include "common/libs/redux/middleware/Middleware.h"

class DuplicatesFinderMiddleware : public Middleware
{
public:
    DuplicatesFinderMiddleware();

    void onAction(std::shared_ptr<Action> action);
};

#endif // DUPLICATESFINDERMIDDLEWARE_H
