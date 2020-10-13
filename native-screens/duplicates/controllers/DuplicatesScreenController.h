#ifndef DUPLICATESSCREENCONTROLLER_H
#define DUPLICATESSCREENCONTROLLER_H

#include <QObject>

class DuplicatesScreenController : public QObject
{
    Q_OBJECT

public:
    DuplicatesScreenController();

    Q_INVOKABLE void addFolderHandler(const QString& folderUrl);
    Q_INVOKABLE void removeFolderButtonHandler(const QString& folderName);
    Q_INVOKABLE void setIncludeFolderSubpaths(const QString& folderName,
                                              const bool includeSubpath);

    Q_INVOKABLE void startScanningButtonHandler();
};

#endif // DUPLICATESSCREENCONTROLLER_H
