#include "DuplicatesScreen.h"
#include "native-screens/duplicates/controllers/DuplicatesScreenController.h"
#include "native-screens/duplicates/models/DuplicatesScreenModel.h"

DuplicatesScreen::DuplicatesScreen(QQmlContext* ctxt) {
    registerScreen(ctxt);
    registerComponents(ctxt);
}

void DuplicatesScreen::registerScreen(QQmlContext* ctxt) {
    ctxt->setContextProperty("DuplicatesScreenModel", new DuplicatesScreenModel());
    ctxt->setContextProperty("DuplicatesScreenController", new DuplicatesScreenController());
}

void DuplicatesScreen::registerComponents(QQmlContext* ctxt) {
    mInputFoldersComponent = new InputFoldersComponent(ctxt);
    mScanningControlsComponent = new ScanningControlsComponent(ctxt);
    mScanningResultsComponent = new ScanningResultsComponent(ctxt);
}
