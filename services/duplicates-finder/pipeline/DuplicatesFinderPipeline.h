#ifndef DUPLICATESFINDERPIPELINE_H
#define DUPLICATESFINDERPIPELINE_H

#include "common/libs/operation/Operation.h"
#include "services/duplicates-finder/pipeline/operations-sequence/OperationsSequence.h"
#include "services/duplicates-finder/data/input-path/InputPath.h"
#include "services/duplicates-finder/data/duplicates-list/DuplicatesList.h"

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
    void pipelineFinished(DuplicatesList duplicates);

public slots:
    void startPipeline(const QList<InputPath> inputPaths);
    void pausePipeline();
    void stopPipeline();

private:
    void doWork();

    QList<InputPath> mInputPaths;
    DuplicatesList mDuplicates;
    OperationsSequence mOperationsSequence;
};

#endif // DUPLICATESFINDERPIPELINE_H
