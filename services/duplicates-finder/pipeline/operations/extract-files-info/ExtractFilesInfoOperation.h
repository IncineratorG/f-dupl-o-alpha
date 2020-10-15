#ifndef EXTRACTFILESINFOOPERATION_H
#define EXTRACTFILESINFOOPERATION_H

#include "common/libs/operation/PipelineOperation.h"
#include "services/duplicates-finder/data/input-path/InputPath.h"
#include "services/duplicates-finder/data/file-info/FileInfo.h"

#include <QList>
#include <QDir>
#include <QSet>

class ExtractFilesInfoOperation : public PipelineOperation<QList<InputPath>, QList<FileInfo>>
{
public:
    ExtractFilesInfoOperation();

    void run();

private:
    QList<QString> getFoldersList();
    QList<FileInfo> getFilesInfo(const QList<QString>& foldersList);

    void getSubfolders(QSet<QString>& foldersSet, const QDir& currentFolder);
};

#endif // EXTRACTFILESINFOOPERATION_H
