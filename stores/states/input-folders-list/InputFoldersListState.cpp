#include "InputFoldersListState.h"

InputFoldersListState::InputFoldersListState() {
    folderNames = std::make_shared<StateProp<QList<QString>>>();

    initState();
}

QList<std::shared_ptr<StatePropLike>> InputFoldersListState::stateProps() const {
    QList<std::shared_ptr<StatePropLike>> props({
                                                    folderNames
                                                });

    return props;
}
