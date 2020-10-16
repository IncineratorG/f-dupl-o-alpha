#include "ScanningControllsController.h"
#include "stores/AppStore.h"
#include "stores/actions/duplicates-finder/DuplicatesFinderActions.h"

#include <QDebug>

ScanningControllsController::ScanningControllsController() {

}

void ScanningControllsController::startScanningButtonHandler() {
    qDebug() << __PRETTY_FUNCTION__;

    const QList<InputPath>& inputPaths = AppStore::get()->inputFoldersListState->inputFolders->value();
    if (inputPaths.length() <= 0) {
        return;
    }

    AppStore::get()->dispatch(
        DuplicatesFinderActions::findDuplicatesAction(inputPaths)
    );
}

void ScanningControllsController::stopScanningButtonHandler() {
    qDebug() << __PRETTY_FUNCTION__ << AppStore::get()->duplicatesFinderState->serviceRunning->value();
}
