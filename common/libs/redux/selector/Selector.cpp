#include "Selector.h"
#include "common/libs/redux/selector/SelectorIdsGenerator.h"

Selector::Selector(const QList<int> propIds, std::function<void(void)> selectorFunc)
    : mPropIds(propIds),
      mSelectorFunc(selectorFunc)
{
    mId = SelectorIdsGenerator::nextId();
}

Selector::Selector(const QList<std::shared_ptr<StatePropLike>> props,
                   std::function<void(void)> selectorFunc)
    : mSelectorFunc(selectorFunc)
{
    for (int i = 0; i < props.length(); ++i) {
        mPropIds.append(props.at(i)->propId());
    }

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
