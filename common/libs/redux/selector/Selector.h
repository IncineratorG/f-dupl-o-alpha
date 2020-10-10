#ifndef SELECTOR_H
#define SELECTOR_H

#include "common/libs/redux/prop/StatePropLike.h"

#include <QList>

#include <memory>
#include <functional>

class Selector
{
public:
    Selector(const QList<int> propIds, std::function<void(void)> selectorFunc);
    Selector(const QList<std::shared_ptr<StatePropLike>> props,
             std::function<void(void)> selectorFunc);

    int id() const;
    QList<int> propIds() const;
    std::function<void(void)> selectorFunc() const;

private:
    int mId;
    QList<int> mPropIds;
    std::function<void(void)> mSelectorFunc;
};

#endif // SELECTOR_H
