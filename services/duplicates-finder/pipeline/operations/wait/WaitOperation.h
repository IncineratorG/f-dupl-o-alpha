#ifndef WAITOPERATION_H
#define WAITOPERATION_H

#include "common/libs/operation/PipelineOperation.h"

class WaitOperation : public PipelineOperation<void*, void*>
{
public:
    WaitOperation();

    void run();
};

#endif // WAITOPERATION_H
