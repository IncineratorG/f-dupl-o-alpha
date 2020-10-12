#include "WaitOperation.h"

#include <QThread>

WaitOperation::WaitOperation() {

}

void WaitOperation::run() {
    QThread::msleep(1000);

    mNotifier.notify(PipelineOperation::FINISHED, nullptr);
}
