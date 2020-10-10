#ifndef SERVICE_H
#define SERVICE_H


class Service
{
public:
    virtual ~Service() = 0;

    virtual void init() = 0;
};

#endif // SERVICE_H
