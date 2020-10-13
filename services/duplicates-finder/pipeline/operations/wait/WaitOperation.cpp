#include "WaitOperation.h"

#include <QThread>
#include <QDebug>

WaitOperation::WaitOperation() {

}

void WaitOperation::run() {
    qDebug() << __PRETTY_FUNCTION__;
    QThread::msleep(1000);
}
