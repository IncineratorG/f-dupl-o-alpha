#ifndef OPERATIONSTRANSITION_H
#define OPERATIONSTRANSITION_H

#include <functional>

class OperationsTransition
{
public:
    OperationsTransition();
    OperationsTransition(std::function<void(void)> action);
    OperationsTransition(const OperationsTransition& other);

    void execute() const;

private:
    std::function<void(void)> mAction;
};

#endif // OPERATIONSTRANSITION_H
