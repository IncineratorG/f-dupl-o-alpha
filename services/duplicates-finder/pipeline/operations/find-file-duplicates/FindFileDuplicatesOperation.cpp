#include "FindFileDuplicatesOperation.h"

#include <QDebug>

FindFileDuplicatesOperation::FindFileDuplicatesOperation() {

}

void FindFileDuplicatesOperation::run() {
    qDebug() << "";
    for (int i = 0; i < mInput.length(); ++i) {
        const FileInfo& fileInfo = mInput.at(i);
        qDebug() << fileInfo.completeBaseName();
    }
    qDebug() << "";
}
