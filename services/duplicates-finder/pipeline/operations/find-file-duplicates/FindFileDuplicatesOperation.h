#ifndef FINDFILEDUPLICATESOPERATION_H
#define FINDFILEDUPLICATESOPERATION_H

#include "common/libs/operation/PipelineOperation.h"
#include "services/duplicates-finder/data/file-info/FileInfo.h"
#include "services/duplicates-finder/data/duplicates-list/DuplicatesList.h"

#include <QList>

class FindFileDuplicatesOperation : public PipelineOperation<QList<FileInfo>, DuplicatesList>
{
public:
    FindFileDuplicatesOperation();

    void run();
};

#endif // FINDFILEDUPLICATESOPERATION_H
