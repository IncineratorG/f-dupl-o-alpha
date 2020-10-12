#ifndef WAITOPERATION_H
#define WAITOPERATION_H

#include "services/duplicates-finder/pipeline/operation/PipelineOperation.h"

class WaitOperation : public PipelineOperation<void*, void*>
{
public:
    WaitOperation();

    void run();
};

#endif // WAITOPERATION_H
