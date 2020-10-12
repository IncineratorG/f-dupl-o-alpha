#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <QString>
#include <QList>
#include <QMap>

#include <any>
#include <functional>

class Notifier
{
public:
    Notifier();

    std::function<void(void)> subscribe(const QString& event,
                                        std::function<void(std::any)> handler);

    void notify(const QString& event, std::any data);

private:
    int mHandlerIdsCounter;
    QMap<int, std::function<void(std::any)>> mEventHandlers;
    QMap<QString, QList<int>> mEventToHandlerIdsMap;
};

#endif // NOTIFIER_H
