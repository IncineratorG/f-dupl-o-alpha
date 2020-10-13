#ifndef OPERATIONSSEQUENCE_H
#define OPERATIONSSEQUENCE_H

#include "common/libs/operation/Operation.h"
#include "services/duplicates-finder/pipeline/operations-transition/OperationsTransition.h"

#include <QList>
#include <QPair>
#include <QMap>

#include <functional>

class OperationsSequence
{
public:
    OperationsSequence();

    OperationsSequence& setNextOperation(Operation* prevOp,
                          Operation* currOp,
                          const OperationsTransition& transition);

    void run() const;

private:
    QList<QPair<Operation*, Operation*>> mOperations;
    QMap<QPair<Operation*, Operation*>, OperationsTransition> mTransitions;
};

#endif // OPERATIONSSEQUENCE_H
