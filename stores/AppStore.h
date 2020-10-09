#ifndef APPSTORE_H
#define APPSTORE_H

#include "stores/middleware/RootMiddleware.h"
#include "common/libs/redux/action/Action.h"
#include "stores/states/test/TestState.h"
#include "stores/reducers/test/TestReducer.h"
#include "common/libs/redux/store/Store.h"

#include <QList>

class AppStore
{
public:
    std::shared_ptr<TestState> testState;

    static AppStore* get();

    void dispatch(std::shared_ptr<Action> action) const;

private:
    AppStore();

    static AppStore* mInstance;

    std::shared_ptr<Middleware> mRootMiddleware;

    QList<std::shared_ptr<Store>> mStores;

    std::shared_ptr<Store> testStore;
};

#endif // APPSTORE_H
