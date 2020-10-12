#include "DuplicatesFinderPipeline.h"

#include <QDebug>
#include <QThread>

DuplicatesFinderPipeline::DuplicatesFinderPipeline() {

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
    QThread::msleep(500);
    qDebug() << __PRETTY_FUNCTION__ << "->FINISHED";
}
