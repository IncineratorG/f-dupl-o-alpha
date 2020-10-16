#ifndef INPUTFOLDERSCONTROLLER_H
#define INPUTFOLDERSCONTROLLER_H

#include <QObject>

class InputFoldersController : public QObject
{
    Q_OBJECT

public:
    InputFoldersController();

    Q_INVOKABLE void addFolderHandler(const QString& folderUrl);
    Q_INVOKABLE void removeFolderButtonHandler(const QString& folderName);
    Q_INVOKABLE void setIncludeFolderSubpaths(const QString& folderName,
                                              const bool includeSubpath);
};

#endif // INPUTFOLDERSCONTROLLER_H
