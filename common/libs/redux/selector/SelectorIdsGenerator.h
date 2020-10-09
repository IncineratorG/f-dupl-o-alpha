#ifndef SELECTORIDSGENERATOR_H
#define SELECTORIDSGENERATOR_H


class SelectorIdsGenerator
{
public:
    static int nextId();

private:
    static int mNextId;
};

#endif // SELECTORIDSGENERATOR_H
