#ifndef DUPLICATESFINDERPIPELINE_H
#define DUPLICATESFINDERPIPELINE_H

#include "services/duplicates-finder/pipeline/operation/Operation.h"

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

    QList<std::shared_ptr<Operation>> mOperation;
};

#endif // DUPLICATESFINDERPIPELINE_H
