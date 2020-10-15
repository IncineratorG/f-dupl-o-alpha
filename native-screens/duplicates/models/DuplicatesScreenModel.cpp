#include "DuplicatesScreenModel.h"
#include "stores/AppStore.h"

DuplicatesScreenModel::DuplicatesScreenModel()
    : mDuplicatesServiceRunning(false)
{
    auto duplicatesState = AppStore::get()->duplicatesFinderState;
    duplicatesState->select(
        Selector(
            {duplicatesState->serviceRunning},
            [this, duplicatesState] () {
                setDuplicatesServiceRunning(duplicatesState->serviceRunning->value());
            }
        )
    );
}

void DuplicatesScreenModel::setDuplicatesServiceRunning(bool value) {
    mDuplicatesServiceRunning = value;
    emit duplicatesServiceRunningChanged(mDuplicatesServiceRunning);
}

bool DuplicatesScreenModel::duplicatesServiceRunning() const {
    return mDuplicatesServiceRunning;
}
