#ifndef APPSTORE_H
#define APPSTORE_H

#include "common/libs/redux/action/Action.h"
#include "common/libs/redux/store/Store.h"
#include "stores/middleware/RootMiddleware.h"
#include "stores/states/test/TestState.h"
#include "stores/reducers/test/TestReducer.h"
#include "stores/states/input-folders-list/InputFoldersListState.h"
#include "stores/reducers/input-folders-list/InputFoldersListReducer.h"

#include <QList>

class AppStore
{
public:
    std::shared_ptr<TestState> testState;
    std::shared_ptr<InputFoldersListState> inputFoldersListState;

    static AppStore* get();

    void dispatch(std::shared_ptr<Action> action) const;

private:
    AppStore();

    static AppStore* mInstance;

    std::shared_ptr<Middleware> mRootMiddleware;

    QList<std::shared_ptr<Store>> mStores;

    std::shared_ptr<Store> testStore;
    std::shared_ptr<Store> inputFoldersListStore;
};

#endif // APPSTORE_H
