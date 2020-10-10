#include "AppStore.h"

AppStore* AppStore::mInstance = nullptr;

AppStore::AppStore()  {
    mRootMiddleware = std::make_shared<RootMiddleware>();

    std::shared_ptr<TestReducer> testReducer(new TestReducer());
    testState = std::make_shared<TestState>();
    testStore = std::make_shared<Store>(testReducer, testState);

    std::shared_ptr<InputFoldersListReducer> inputFoldersListReducer(new InputFoldersListReducer());
    inputFoldersListState = std::make_shared<InputFoldersListState>();
    inputFoldersListStore = std::make_shared<Store>(inputFoldersListReducer, inputFoldersListState);

    mStores.append({
                    testStore,
                    inputFoldersListStore
                });
}

AppStore* AppStore::get() {
    if (!mInstance) {
        mInstance = new AppStore();
    }

    return mInstance;
}

void AppStore::dispatch(std::shared_ptr<Action> action) const {
    mRootMiddleware->onAction(action);

    for (int i = 0; i < mStores.length(); ++i) {
        mStores.at(i)->dispatch(action);
    }
}
