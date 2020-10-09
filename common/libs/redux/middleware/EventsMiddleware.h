#ifndef EVENTSMIDDLEWARE_H
#define EVENTSMIDDLEWARE_H


class EventsMiddleware
{
public:
    virtual ~EventsMiddleware() = 0;

    virtual void init() = 0;
};

#endif // EVENTSMIDDLEWARE_H
