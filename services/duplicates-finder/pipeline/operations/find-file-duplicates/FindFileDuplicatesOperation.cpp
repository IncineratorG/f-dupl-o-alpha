#include "FindFileDuplicatesOperation.h"

#include <QDebug>
#include <QtConcurrent/QtConcurrent>

#include <functional>

FindFileDuplicatesOperation::FindFileDuplicatesOperation() {

}

void FindFileDuplicatesOperation::run() {
    QList<QString> list;
    for (int i = 0; i < 5; ++i) {
        list.append(QString::number(i));
    }

    std::function<QString(const QString&)> map = [] (const QString& str) {
        return QString(str).append("_m");
    };

    QList<QString> anotherList = QtConcurrent::blockingMapped(list, map);

    for (int i = 0; i < anotherList.length(); ++i) {
        qDebug() << anotherList.at(i);
    }

//    qDebug() << "";
//    for (int i = 0; i < mInput.length(); ++i) {
//        const FileInfo& fileInfo = mInput.at(i);
//        qDebug() << fileInfo.completeBaseName();
//    }
//    qDebug() << "";
}
