#include "DuplicatesFinderState.h"

DuplicatesFinderState::DuplicatesFinderState() {
    duplicates = std::make_shared<StateProp<DuplicatesList>>();
    serviceRunning = std::make_shared<StateProp<bool>>(false);

    initState();
}

QList<std::shared_ptr<StatePropLike>> DuplicatesFinderState::stateProps() const {
    QList<std::shared_ptr<StatePropLike>> props({
        duplicates,
        serviceRunning
    });

    return props;
}
