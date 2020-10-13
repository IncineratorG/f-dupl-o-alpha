#ifndef INPUTFOLDERSLISTSTATE_H
#define INPUTFOLDERSLISTSTATE_H

#include "common/libs/redux/state/State.h"
#include "common/libs/redux/prop/StatePropLike.h"
#include "common/libs/redux/prop/StateProp.h"
#include "services/duplicates-finder/data/input-path/InputPath.h"

#include <QList>

class InputFoldersListState : public State
{
public:
    std::shared_ptr<StateProp<QList<QString>>> folderNames;
    std::shared_ptr<StateProp<QList<InputPath>>> inputFolders;

    InputFoldersListState();

protected:
    QList<std::shared_ptr<StatePropLike> > stateProps() const;
};

#endif // INPUTFOLDERSLISTSTATE_H
