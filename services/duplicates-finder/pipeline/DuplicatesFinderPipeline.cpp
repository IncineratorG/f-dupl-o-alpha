#include "DuplicatesFinderPipeline.h"
#include "services/duplicates-finder/pipeline/operations/wait/WaitOperation.h"
#include "services/duplicates-finder/pipeline/operations/extract-files-info/ExtractFilesInfoOperation.h"
#include "services/duplicates-finder/pipeline/operations/find-file-duplicates/FindFileDuplicatesOperation.h"

#include <QDebug>

DuplicatesFinderPipeline::DuplicatesFinderPipeline() {
    auto extractFilesInfo = new ExtractFilesInfoOperation();
    auto findFileDuplicates = new FindFileDuplicatesOperation();

    mOperationsSequence.setNextOperation(nullptr,
                                         extractFilesInfo,
                                         OperationsTransition([this, extractFilesInfo] () {
        extractFilesInfo->setInput(mInputPaths);
    }));
    mOperationsSequence.setNextOperation(extractFilesInfo,
                                         findFileDuplicates,
                                         OperationsTransition([extractFilesInfo, findFileDuplicates] () {
        findFileDuplicates->setInput(extractFilesInfo->output());
    }));
    mOperationsSequence.setNextOperation(findFileDuplicates,
                                         nullptr,
                                         OperationsTransition([this, findFileDuplicates] () {
        mDuplicates = findFileDuplicates->output();
    }));
}

void DuplicatesFinderPipeline::startPipeline(const QList<InputPath> inputPaths) {
    mInputPaths = inputPaths;

    emit pipelineStarted();

    doWork();

    emit pipelineFinished(mDuplicates);
}

void DuplicatesFinderPipeline::pausePipeline() {
    emit pipelinePaused();
}

void DuplicatesFinderPipeline::stopPipeline() {
    emit pipelineStopped();
}

void DuplicatesFinderPipeline::doWork() {
    mOperationsSequence.run();
}
