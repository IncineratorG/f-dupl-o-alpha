#ifndef SCANNINGCONTROLLSCONTROLLER_H
#define SCANNINGCONTROLLSCONTROLLER_H

#include <QObject>

class ScanningControllsController : public QObject
{
    Q_OBJECT

public:
    ScanningControllsController();

    Q_INVOKABLE void startScanningButtonHandler();
    Q_INVOKABLE void stopScanningButtonHandler();
};

#endif // SCANNINGCONTROLLSCONTROLLER_H
