#ifndef STATE_H
#define STATE_H

#include "common/libs/redux/selector/Selector.h"
#include "common/libs/redux/prop/StatePropLike.h"
#include "native-screens/test/TestScreen.h"

#include <QList>
#include <QMap>

#include <memory>
#include <functional>

class State
{
public:
    State();
    virtual ~State() = 0;

    std::function<void(void)> select(Selector selector);
    void update(std::function<void(void)> updater);

protected:
    void initState();
    virtual QList<std::shared_ptr<StatePropLike>> stateProps() const = 0;

private:
    QList<std::shared_ptr<StatePropLike>> mStateProps;
    QMap<int, QList<Selector>> mPropSelectorsMap;

    void notifySelectors() const;
};

#endif // STATE_H
