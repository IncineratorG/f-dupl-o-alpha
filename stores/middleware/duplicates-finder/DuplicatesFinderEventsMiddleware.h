#ifndef DUPLICATESFINDEREVENTSMIDDLEWARE_H
#define DUPLICATESFINDEREVENTSMIDDLEWARE_H

#include "common/libs/redux/middleware/EventsMiddleware.h"

class DuplicatesFinderEventsMiddleware : public EventsMiddleware
{
public:
    DuplicatesFinderEventsMiddleware();

    void init();
};

#endif // DUPLICATESFINDEREVENTSMIDDLEWARE_H
