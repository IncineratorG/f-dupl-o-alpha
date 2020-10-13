#ifndef OPERATION_H
#define OPERATION_H


class Operation
{
public:
    virtual ~Operation() = 0;

    virtual void run() = 0;
};

#endif // OPERATION_H
