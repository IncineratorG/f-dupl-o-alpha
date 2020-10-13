#ifndef EXTRACTFILESINFOOPERATION_H
#define EXTRACTFILESINFOOPERATION_H

#include "common/libs/operation/PipelineOperation.h"
#include "services/duplicates-finder/data/input-path/InputPath.h"

#include <QList>

class ExtractFilesInfoOperation : public PipelineOperation<QList<InputPath>, void*>
{
public:
    ExtractFilesInfoOperation();

    void run();
};

#endif // EXTRACTFILESINFOOPERATION_H
