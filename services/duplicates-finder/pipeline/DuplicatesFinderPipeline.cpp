#include "DuplicatesFinderPipeline.h"
#include "services/duplicates-finder/pipeline/operations/wait/WaitOperation.h"
#include "services/duplicates-finder/pipeline/operations/extract-files-info/ExtractFilesInfoOperation.h"
#include "services/duplicates-finder/pipeline/operations/find-file-duplicates/FindFileDuplicatesOperation.h"

#include <QDebug>

DuplicatesFinderPipeline::DuplicatesFinderPipeline() {
    auto wait = new WaitOperation();
    auto extractFilesInfo = new ExtractFilesInfoOperation();
    auto findFileDuplicates = new FindFileDuplicatesOperation();

    mOperationsSequence.setNextOperation(nullptr,
                                         extractFilesInfo,
                                         OperationsTransition([this, extractFilesInfo] () {
        extractFilesInfo->setInput(mInputPaths);
    }));
    mOperationsSequence.setNextOperation(extractFilesInfo,
                                         findFileDuplicates,
                                         OperationsTransition([this, extractFilesInfo, findFileDuplicates] () {
        findFileDuplicates->setInput(extractFilesInfo->output());
    }));
    mOperationsSequence.setNextOperation(findFileDuplicates,
                                         nullptr,
                                         OperationsTransition());
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
