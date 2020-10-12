#include "Notifier.h"

#include <QDebug>

Notifier::Notifier()
    : mHandlerIdsCounter(1)
{

}

std::function<void(void)> Notifier::subscribe(const QString& event,
                                              std::function<void (std::any)> handler) {
    int handlerId = ++mHandlerIdsCounter;

    mEventHandlers.insert(handlerId, handler);

    QList<int> eventHandlerIds = mEventToHandlerIdsMap.value(event, {});
    eventHandlerIds.append(handlerId);
    mEventToHandlerIdsMap.insert(event, eventHandlerIds);

    auto unsubscribe = [this, event, handlerId] () {
        mEventHandlers.remove(handlerId);

        QList<int> eventHandlerIds = mEventToHandlerIdsMap.value(event);
        for (int i = 0; i < eventHandlerIds.length(); ++i) {
            if (eventHandlerIds.at(i) == handlerId) {
                eventHandlerIds.removeAt(i);
                break;
            }
        }

        mEventToHandlerIdsMap.insert(event, eventHandlerIds);
    };

    return unsubscribe;
}

void Notifier::notify(const QString &event, std::any data) {
    const QList<int> eventHandlerIds = mEventToHandlerIdsMap.value(event);
    for (int i = 0; i < eventHandlerIds.length(); ++i) {
        const int handlerId = eventHandlerIds.at(i);

        try {
            mEventHandlers.value(handlerId)(data);
        } catch (std::exception e) {
            qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION";
        }
    }
}
