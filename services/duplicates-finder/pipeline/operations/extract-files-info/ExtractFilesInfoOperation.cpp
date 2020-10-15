#include "ExtractFilesInfoOperation.h"

#include <QDebug>
#include <QFileInfoList>

ExtractFilesInfoOperation::ExtractFilesInfoOperation() {

}

void ExtractFilesInfoOperation::run() {
    const QList<QString>& foldersList = getFoldersList();
    const QList<FileInfo>& filesInfo = getFilesInfo(foldersList);

    mOutput = filesInfo;
}

QList<QString> ExtractFilesInfoOperation::getFoldersList() {
    QSet<QString> foldersSet;

    for (int i = 0; i < mInput.length(); ++i) {
        const QString folderPath = mInput.at(i).path();
        const bool includeSubpath = mInput.at(i).includeSubpath();

        if (includeSubpath) {
            getSubfolders(foldersSet, QDir(folderPath));
        } else {
            foldersSet.insert(folderPath);
        }
    }

    return foldersSet.toList();
}

QList<FileInfo> ExtractFilesInfoOperation::getFilesInfo(const QList<QString>& foldersList) {
    QList<FileInfo> filesInfo;

    for (int i = 0; i < foldersList.length(); ++i) {
        const QString& folderPath = foldersList.at(i);

        const QFileInfoList directoryInfoList = QDir(folderPath).entryInfoList(QDir::NoDotAndDotDot | QDir::Files);
        for (int j = 0; j < directoryInfoList.length(); ++j) {
            const QFileInfo& fileInfo = directoryInfoList.at(j);

            if (fileInfo.isHidden()) {
                continue;
            } else if (fileInfo.isDir()) {
                continue;
            }

            filesInfo.append(FileInfo(fileInfo));
        }
    }

    return filesInfo;
}

void ExtractFilesInfoOperation::getSubfolders(QSet<QString>& foldersSet, const QDir& currentFolder) {
    foldersSet.insert(currentFolder.absolutePath());

    const QFileInfoList directoryInfoList = QDir(currentFolder).entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Dirs);
    for (int i = 0; i < directoryInfoList.length(); ++i) {
        const QFileInfo& fileInfo = directoryInfoList.at(i);

        if (fileInfo.isHidden()) {
            continue;
        }

        if (fileInfo.isDir()) {
            getSubfolders(foldersSet, QDir(fileInfo.absoluteFilePath()));
        }
    }
}
