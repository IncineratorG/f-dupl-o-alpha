#include "DuplicatesFinderState.h"

DuplicatesFinderState::DuplicatesFinderState() {
    initState();
}

QList<std::shared_ptr<StatePropLike>> DuplicatesFinderState::stateProps() const {
    QList<std::shared_ptr<StatePropLike>> props({

                                                });

    return props;
}
