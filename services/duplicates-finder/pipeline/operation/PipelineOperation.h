#ifndef PIPELINEOPERATION_H
#define PIPELINEOPERATION_H

#include "services/duplicates-finder/pipeline/operation/Operation.h"
#include "utils/common/notifier/Notifier.h"

#include <QString>

template <class I, class O> class PipelineOperation : public Operation
{
public:
    const QString FINISHED = "FINISHED";

    PipelineOperation() {

    }

    std::function<void(void)> subscribe(const QString& event,
                                        std::function<void(std::any)> handler) {
        return mNotifier.subscribe(event, handler);
    }

    void setInput(I value) {
        mInput = value;
    }

    O output() const {
        return mOutput;
    }

    virtual void run() = 0;

protected:
    I mInput;
    O mOutput;

    Notifier mNotifier;
};

#endif // PIPELINEOPERATION_H
