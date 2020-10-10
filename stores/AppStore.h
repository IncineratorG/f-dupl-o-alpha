#ifndef APPSTORE_H
#define APPSTORE_H

#include "common/libs/redux/action/Action.h"
#include "common/libs/redux/store/Store.h"
#include "stores/middleware/RootMiddleware.h"
#include "stores/states/test/TestState.h"
#include "stores/reducers/test/TestReducer.h"
#include "stores/states/input-folders-list/InputFoldersListState.h"
#include "stores/reducers/input-folders-list/InputFoldersListReducer.h"
#include "stores/states/system/SystemState.h"
#include "stores/reducers/system/SystemReducer.h"
#include "stores/states/duplicates-finder/DuplicatesFinderState.h"
#include "stores/reducers/duplicates-finder/DuplicatesFinderReducer.h"

#include <QList>

class AppStore
{
public:
    std::shared_ptr<TestState> testState;
    std::shared_ptr<InputFoldersListState> inputFoldersListState;
    std::shared_ptr<SystemState> systemState;
    std::shared_ptr<DuplicatesFinderState> duplicatesFinderState;

    static AppStore* get();

    void dispatch(std::shared_ptr<Action> action) const;

private:
    AppStore();

    static AppStore* mInstance;

    std::shared_ptr<Middleware> mRootMiddleware;

    QList<std::shared_ptr<Store>> mStores;

    std::shared_ptr<Store> mTestStore;
    std::shared_ptr<Store> mInputFoldersListStore;
    std::shared_ptr<Store> mSystemStore;
    std::shared_ptr<Store> mDuplicatesFinderStore;
};

#endif // APPSTORE_H
