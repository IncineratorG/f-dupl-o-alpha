#ifndef DUPLICATESFINDERPIPELINE_H
#define DUPLICATESFINDERPIPELINE_H

#include "common/libs/operation/Operation.h"
#include "services/duplicates-finder/pipeline/operations-sequence/OperationsSequence.h"

#include <QObject>
#include <QList>

#include <memory>

class DuplicatesFinderPipeline : public QObject
{
    Q_OBJECT

public:
    DuplicatesFinderPipeline();

signals:
    void pipelineStarted();
    void pipelinePaused();
    void pipelineStopped();
    void pipelineFinished();

public slots:
    void startPipeline();
    void pausePipeline();
    void stopPipeline();

private:
    void doWork();

    OperationsSequence mOperationsSequence;
};

#endif // DUPLICATESFINDERPIPELINE_H
