#include "DuplicatesFinderService.h"
#include "services/duplicates-finder/event-types/DuplicatesFinderServiceEventTypes.h"

#include <QDebug>

DuplicatesFinderService::DuplicatesFinderService() {
    mPipeline.moveToThread(&mPipelineThread);

    connect(this, SIGNAL(startPipeline(const QList<InputPath>)), &mPipeline, SLOT(startPipeline(const QList<InputPath>)));
    connect(this, SIGNAL(pausePipeline()), &mPipeline, SLOT(pausePipeline()));
    connect(this, SIGNAL(stopPipeline()), &mPipeline, SLOT(stopPipeline()));

    connect(&mPipeline, SIGNAL(pipelineStarted()), this, SLOT(onPipelineStarted()));
    connect(&mPipeline, SIGNAL(pipelinePaused()), this, SLOT(onPipelinePaused()));
    connect(&mPipeline, SIGNAL(pipelineStopped()), this, SLOT(onPipelineStopped()));
    connect(&mPipeline, SIGNAL(pipelineFinished(DuplicatesList)), this, SLOT(onPipelineFinished(DuplicatesList)));

    mPipelineThread.start();
}

void DuplicatesFinderService::init() {

}

std::function<void(void)> DuplicatesFinderService::subscribe(const QString& event,
                                                             std::function<void(std::any)> handler) {
    return mNotifier.subscribe(event, handler);
}

void DuplicatesFinderService::start(const QList<InputPath> inputPaths) {
//    qDebug() << __PRETTY_FUNCTION__ << inputPaths.length();

    emit startPipeline(inputPaths);
}

void DuplicatesFinderService::pause() {
    qDebug() << __PRETTY_FUNCTION__;

    emit pausePipeline();
}

void DuplicatesFinderService::stop() {
    qDebug() << __PRETTY_FUNCTION__;

    emit stopPipeline();
}

void DuplicatesFinderService::onPipelineStarted() {
    qDebug() << __PRETTY_FUNCTION__;

    mNotifier.notify(DuplicatesFinderServiceEventTypes::SERVICE_STARTED, nullptr);
}

void DuplicatesFinderService::onPipelinePaused() {
    qDebug() << __PRETTY_FUNCTION__;

    mNotifier.notify(DuplicatesFinderServiceEventTypes::SERVICE_PAUSED, nullptr);
}

void DuplicatesFinderService::onPipelineStopped() {
    qDebug() << __PRETTY_FUNCTION__;

    mNotifier.notify(DuplicatesFinderServiceEventTypes::SERVICE_STOPPED, nullptr);
}

void DuplicatesFinderService::onPipelineFinished(DuplicatesList duplicates) {
    mNotifier.notify(DuplicatesFinderServiceEventTypes::SERVICE_FINISHED, duplicates);
}
