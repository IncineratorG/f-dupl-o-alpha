#include "FindFileDuplicatesOperation.h"

#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include <QMap>
#include <QSet>

#include <functional>

FindFileDuplicatesOperation::FindFileDuplicatesOperation() {

}

void FindFileDuplicatesOperation::run() {
    mOutput.clear();

    QSet<FileInfo> scannedFiles;

    for (int i = 0; i < mInput.length(); ++i) {
        const FileInfo& currentFile = mInput.at(i);

        QList<FileInfo> currentFileDuplicates;
        for (int j = i + 1; j < mInput.length(); ++j) {
            const FileInfo& otherFile = mInput.at(j);

            if (scannedFiles.contains(otherFile)) {
                continue;
            }

            if (currentFile.bytesSize() == otherFile.bytesSize()
                && currentFile.suffix() == otherFile.suffix()
                && currentFile.completeBaseName() == otherFile.completeBaseName())
            {
                currentFileDuplicates.append(otherFile);
                scannedFiles.insert(otherFile);
            }
        }

        if (currentFileDuplicates.length() > 0) {
            mOutput.addDuplicates(currentFile, currentFileDuplicates);
        }
    }
}

//    std::function<QString(const QString&)> map = [] (const QString& str) {
//        return QString(str).append("_m");
//    };

//    QList<QString> anotherList = QtConcurrent::blockingMapped(list, map);

//    for (int i = 0; i < anotherList.length(); ++i) {
//        qDebug() << anotherList.at(i);
//    }
