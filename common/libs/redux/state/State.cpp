#include "State.h"
#include "common/libs/redux/state/StatePropIdsGenerator.h"

#include <QDebug>
#include <QSet>

State::State() {

}

State::~State() {

}

void State::initState() {
    auto props = stateProps();
    for (int i = 0; i < props.length(); ++i) {
        props.at(i)->setPropId(StatePropIdsGenerator::nextId());
    }
}

std::function<void(void)> State::select(Selector selector) {
    QList<int> selectorPropIds = selector.propIds();

    for (int i = 0; i < selectorPropIds.length(); ++i) {
        int selectorPropId = selectorPropIds.at(i);

        QList<Selector> selectorsList = mPropSelectorsMap.value(selectorPropId, {});
        selectorsList.append(selector);
        mPropSelectorsMap.insert(selectorPropId, selectorsList);
    }

    try {
        selector.selectorFunc()();
    } catch (std::exception e) {
        qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION";
    }

    const int selectorId = selector.id();
    std::function<void(void)> unsubscribe = [this, selectorPropIds, selectorId] () {
        for (int selectorPropIndex = 0; selectorPropIndex < selectorPropIds.length(); ++selectorPropIndex) {
            int selectorPropId = selectorPropIds.at(selectorPropIndex);

            QList<Selector> selectorsList = mPropSelectorsMap.value(selectorPropId);
            for (int selectorIndex = 0; selectorIndex < selectorsList.length(); ++selectorIndex) {
                if (selectorsList.at(selectorIndex).id() == selectorId) {
                    selectorsList.removeAt(selectorIndex);
                    break;
                }
            }
            if (selectorsList.length() <= 0) {
                mPropSelectorsMap.remove(selectorPropId);
            } else {
                mPropSelectorsMap.insert(selectorPropId, selectorsList);
            }
        }
    };

    return unsubscribe;
}

void State::update(std::function<void ()> updater) {
    try {
        updater();
    } catch (std::exception e) {
        qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION";
        return;
    }

    notifySelectors();
}

void State::notifySelectors() const {
    QSet<int> invokedSelectorIds;

    auto props = stateProps();

    for (int propIndex = 0; propIndex < props.length(); ++propIndex) {
        auto prop = props.at(propIndex);
        if (prop->updated()) {
            int propId = prop->propId();

            if (mPropSelectorsMap.contains(propId)) {
                QList<Selector> selectorsList = mPropSelectorsMap.value(propId);
                for (int selectorIndex = 0; selectorIndex < selectorsList.length(); ++selectorIndex) {
                    const int selectorId = selectorsList.at(selectorIndex).id();

                    if (!invokedSelectorIds.contains(selectorId)) {
                        try {
                            selectorsList.at(selectorIndex).selectorFunc()();
                        } catch (std::exception e) {
                            qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION";
                            return;
                        }
                        invokedSelectorIds.insert(selectorId);
                    }
                }
            }
        }

        prop->setUpdated(false);
    }
}
