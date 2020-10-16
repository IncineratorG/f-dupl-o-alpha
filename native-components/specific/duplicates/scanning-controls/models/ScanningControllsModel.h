#ifndef SCANNINGCONTROLLSMODEL_H
#define SCANNINGCONTROLLSMODEL_H

#include <QObject>

class ScanningControllsModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool duplicatesServiceRunning WRITE setDuplicatesServiceRunning READ duplicatesServiceRunning NOTIFY duplicatesServiceRunningChanged)

public:
    ScanningControllsModel();

    void setDuplicatesServiceRunning(bool value);

    bool duplicatesServiceRunning() const;

signals:
    void duplicatesServiceRunningChanged(bool value);

private:
    bool mDuplicatesServiceRunning;
};

#endif // SCANNINGCONTROLLSMODEL_H
