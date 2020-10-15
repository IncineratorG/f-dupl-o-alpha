#ifndef DUPLICATESSCREENMODEL_H
#define DUPLICATESSCREENMODEL_H

#include <QObject>

class DuplicatesScreenModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool duplicatesServiceRunning WRITE setDuplicatesServiceRunning READ duplicatesServiceRunning NOTIFY duplicatesServiceRunningChanged)

public:
    DuplicatesScreenModel();

    void setDuplicatesServiceRunning(bool value);

    bool duplicatesServiceRunning() const;

signals:
    void duplicatesServiceRunningChanged(bool value);

private:
    bool mDuplicatesServiceRunning;
};

#endif // DUPLICATESSCREENMODEL_H
