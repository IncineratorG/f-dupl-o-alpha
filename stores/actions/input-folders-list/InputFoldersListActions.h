#ifndef INPUTFOLDERSLISTACTIONS_H
#define INPUTFOLDERSLISTACTIONS_H

#include "common/libs/redux/action/Action.h"

#include <memory>

class InputFoldersListActions
{
public:
    static std::shared_ptr<Action> addFolderNameAction(const QString& folderName);
    static std::shared_ptr<Action> removeFolderNameAction(const QString& folderName);
};

#endif // INPUTFOLDERSLISTACTIONS_H
