#include "OperationsTransition.h"

OperationsTransition::OperationsTransition() {

}

OperationsTransition::OperationsTransition(std::function<void(void)> action)
    : mAction(action)
{

}

OperationsTransition::OperationsTransition(const OperationsTransition& other)
    : mAction(other.mAction)
{

}

void OperationsTransition::execute() const {
    try {
        mAction();
    } catch (std::exception e) {

    }
}
