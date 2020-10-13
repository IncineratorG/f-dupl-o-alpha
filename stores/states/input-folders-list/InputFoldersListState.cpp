#include "InputFoldersListState.h"

InputFoldersListState::InputFoldersListState() {
    folderNames = std::make_shared<StateProp<QList<QString>>>();
    inputFolders = std::make_shared<StateProp<QList<InputPath>>>();

    initState();
}

QList<std::shared_ptr<StatePropLike>> InputFoldersListState::stateProps() const {
    QList<std::shared_ptr<StatePropLike>> props({
                                                    folderNames,
                                                    inputFolders
                                                });

    return props;
}
