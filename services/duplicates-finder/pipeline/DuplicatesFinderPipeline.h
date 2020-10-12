#ifndef DUPLICATESFINDERPIPELINE_H
#define DUPLICATESFINDERPIPELINE_H

#include <QObject>

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
};

#endif // DUPLICATESFINDERPIPELINE_H
