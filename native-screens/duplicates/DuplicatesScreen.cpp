#include "DuplicatesScreen.h"
#include "native-screens/duplicates/controllers/DuplicatesScreenController.h"
#include "native-screens/duplicates/models/DuplicateScreenModel.h"

DuplicatesScreen::DuplicatesScreen(QQmlContext* ctxt) {
    registerScreen(ctxt);
}

void DuplicatesScreen::registerScreen(QQmlContext* ctxt) {
    ctxt->setContextProperty("DuplicatesScreenController", new DuplicatesScreenController());
    ctxt->setContextProperty("DuplicatesScreenModel", new DuplicateScreenModel());
}
