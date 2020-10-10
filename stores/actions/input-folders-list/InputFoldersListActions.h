#ifndef INPUTFOLDERSLISTACTIONS_H
#define INPUTFOLDERSLISTACTIONS_H

#include "common/libs/redux/action/Action.h"

#include <memory>

class InputFoldersListActions
{
public:
    static std::shared_ptr<Action> addFolderNameAction(const QString& folderName);
};

#endif // INPUTFOLDERSLISTACTIONS_H
