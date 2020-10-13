#include "DuplicatesFinderPipeline.h"
#include "services/duplicates-finder/pipeline/operations/wait/WaitOperation.h"

#include <QDebug>
#include <QThread>

DuplicatesFinderPipeline::DuplicatesFinderPipeline() {
    WaitOperation* waitOperation_1 = new WaitOperation();
    WaitOperation* waitOperation_2 = new WaitOperation();

//    mOperationsSequence.setNextOperation(nullptr, waitOperation_1, OperationsTransition([] () {
//        qDebug() << "FROM NULL TO OP_1";
//    }));
//    mOperationsSequence.setNextOperation(waitOperation_1, waitOperation_2, OperationsTransition([] () {
//        qDebug() << "FROM OP_1 TO OP_2";
//    }));
//    mOperationsSequence.setNextOperation(waitOperation_2, nullptr, OperationsTransition([] () {
//        qDebug() << "FROM OP_2 TO NULL";
//    }));
}

void DuplicatesFinderPipeline::startPipeline() {
    qDebug() << __PRETTY_FUNCTION__;

    emit pipelineStarted();

    doWork();

    emit pipelineFinished();
}

void DuplicatesFinderPipeline::pausePipeline() {
    qDebug() << __PRETTY_FUNCTION__;

    emit pipelinePaused();
}

void DuplicatesFinderPipeline::stopPipeline() {
    qDebug() << __PRETTY_FUNCTION__;

    emit pipelineStopped();
}

void DuplicatesFinderPipeline::doWork() {
    qDebug() << __PRETTY_FUNCTION__ << "->START";

    mOperationsSequence.run();

    qDebug() << __PRETTY_FUNCTION__ << "->FINISHED";
}
