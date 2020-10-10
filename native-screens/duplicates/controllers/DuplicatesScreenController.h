#ifndef DUPLICATESSCREENCONTROLLER_H
#define DUPLICATESSCREENCONTROLLER_H

#include <QObject>

class DuplicatesScreenController : public QObject
{
    Q_OBJECT

public:
    DuplicatesScreenController();

    Q_INVOKABLE void addFolderButtonHandler();
    Q_INVOKABLE void removeFolderButtonHandler();
};

#endif // DUPLICATESSCREENCONTROLLER_H
