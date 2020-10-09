#include "Selector.h"
#include "common/libs/redux/selector/SelectorIdsGenerator.h"

Selector::Selector(const QList<int> propIds, std::function<void(void)> selectorFunc)
    : mPropIds(propIds),
      mSelectorFunc(selectorFunc)
{
    mId = SelectorIdsGenerator::nextId();
}

int Selector::id() const {
    return mId;
}

QList<int> Selector::propIds() const {
    return mPropIds;
}

std::function<void(void)> Selector::selectorFunc() const {
    return mSelectorFunc;
}
