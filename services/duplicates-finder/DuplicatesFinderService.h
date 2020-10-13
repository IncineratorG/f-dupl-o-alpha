#ifndef DUPLICATESFINDERSERVICE_H
#define DUPLICATESFINDERSERVICE_H

#include "common/libs/service/Service.h"
#include "services/duplicates-finder/pipeline/DuplicatesFinderPipeline.h"
#include "services/duplicates-finder/data/input-path/InputPath.h"
#include "utils/common/notifier/Notifier.h"

#include <QObject>
#include <QThread>
#include <QString>
#include <QList>

class DuplicatesFinderService : public QObject, public Service
{
    Q_OBJECT

public:
    DuplicatesFinderService();

    void init();

    std::function<void(void)> subscribe(const QString& event,
                                        std::function<void(std::any)> handler);

    void start(const QList<InputPath> inputPaths);
    void pause();
    void stop();

signals:
    void startPipeline(const QList<InputPath> inputPaths);
    void pausePipeline();
    void stopPipeline();

private slots:
    void onPipelineStarted();
    void onPipelinePaused();
    void onPipelineStopped();
    void onPipelineFinished();

private:
    Notifier mNotifier;

    QThread mPipelineThread;

    DuplicatesFinderPipeline mPipeline;
};

#endif // DUPLICATESFINDERSERVICE_H
