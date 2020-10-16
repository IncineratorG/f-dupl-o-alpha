#include "ScanningControllsModel.h"
#include "stores/AppStore.h"

#include <QDebug>

ScanningControllsModel::ScanningControllsModel()
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

void ScanningControllsModel::setDuplicatesServiceRunning(bool value) {
    mDuplicatesServiceRunning = value;
    emit duplicatesServiceRunningChanged(mDuplicatesServiceRunning);
}

bool ScanningControllsModel::duplicatesServiceRunning() const {
    return mDuplicatesServiceRunning;
}
