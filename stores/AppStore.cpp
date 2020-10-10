#include "AppStore.h"

AppStore* AppStore::mInstance = nullptr;

AppStore::AppStore()  {
    mRootMiddleware = std::make_shared<RootMiddleware>();

    std::shared_ptr<TestReducer> testReducer(new TestReducer());
    testState = std::make_shared<TestState>();
    mTestStore = std::make_shared<Store>(testReducer, testState);

    std::shared_ptr<InputFoldersListReducer> inputFoldersListReducer(new InputFoldersListReducer());
    inputFoldersListState = std::make_shared<InputFoldersListState>();
    mInputFoldersListStore = std::make_shared<Store>(inputFoldersListReducer, inputFoldersListState);

    std::shared_ptr<SystemReducer> systemReducer(new SystemReducer());
    systemState = std::make_shared<SystemState>();
    mSystemStore = std::make_shared<Store>(systemReducer, systemState);

    std::shared_ptr<DuplicatesFinderReducer> duplicatesFinderReducer(new DuplicatesFinderReducer());
    duplicatesFinderState = std::make_shared<DuplicatesFinderState>();
    mDuplicatesFinderStore = std::make_shared<Store>(duplicatesFinderReducer, duplicatesFinderState);

    mStores.append({
                    mTestStore,
                    mInputFoldersListStore,
                    mSystemStore,
                    mDuplicatesFinderStore
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
