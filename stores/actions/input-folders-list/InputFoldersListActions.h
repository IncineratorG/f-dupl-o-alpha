#ifndef INPUTFOLDERSLISTACTIONS_H
#define INPUTFOLDERSLISTACTIONS_H

#include "common/libs/redux/action/Action.h"

#include <memory>

class InputFoldersListActions
{
public:
    static std::shared_ptr<Action> addFolderAction(const QString& folderName,
                                                       const bool includeSubpath = true);
    static std::shared_ptr<Action> removeFolderAction(const QString& folderName);
    static std::shared_ptr<Action> updateFolderAction(const QString& folderName,
                                                      const bool includeSubpath);
};

#endif // INPUTFOLDERSLISTACTIONS_H
