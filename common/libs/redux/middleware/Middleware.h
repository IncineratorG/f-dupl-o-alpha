#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "common/libs/redux/action/Action.h"

#include <memory>

class Middleware
{
public:
    virtual ~Middleware() = 0;

    virtual void onAction(std::shared_ptr<Action> action) = 0;
};

#endif // MIDDLEWARE_H
