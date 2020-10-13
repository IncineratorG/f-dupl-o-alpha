#include "DuplicatesFinderPipeline.h"
#include "services/duplicates-finder/pipeline/operations/wait/WaitOperation.h"
#include "services/duplicates-finder/pipeline/operations/extract-files-info/ExtractFilesInfoOperation.h"

#include <QDebug>

DuplicatesFinderPipeline::DuplicatesFinderPipeline() {
    WaitOperation* wait = new WaitOperation();
    ExtractFilesInfoOperation* extractFilesInfo = new ExtractFilesInfoOperation();

    mOperationsSequence.setNextOperation(nullptr, extractFilesInfo, OperationsTransition([this, extractFilesInfo] () {
        extractFilesInfo->setInput(mInputPaths);
    }));
    mOperationsSequence.setNextOperation(extractFilesInfo, nullptr, OperationsTransition());

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

void DuplicatesFinderPipeline::startPipeline(const QList<InputPath> inputPaths) {
    qDebug() << __PRETTY_FUNCTION__ << inputPaths.length();
    mInputPaths = inputPaths;

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
