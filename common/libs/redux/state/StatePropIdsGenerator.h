#ifndef STATEPROPIDSGENERATOR_H
#define STATEPROPIDSGENERATOR_H


class StatePropIdsGenerator
{
public:
    static int nextId();

private:
    static int mNextId;
};

#endif // STATEPROPIDSGENERATOR_H
