#include "OperationsSequence.h"

OperationsSequence::OperationsSequence() {

}

OperationsSequence& OperationsSequence::setNextOperation(Operation* prevOp,
                                          Operation* currOp,
                                          const OperationsTransition& transition) {
    auto operations = qMakePair(prevOp, currOp);

    mOperations.append(operations);
    mTransitions.insert(operations, transition);

    return *this;
}

void OperationsSequence::run() const {
    for (int i = 0; i < mOperations.length(); ++i) {
        auto operations = mOperations.at(i);
        auto currOp = operations.first;

        auto transition = mTransitions.value(operations);

        if (currOp != nullptr) {
            currOp->run();
        }

        transition.execute();
    }
}
