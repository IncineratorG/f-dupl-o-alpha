#include "TestScreen.h"
#include "models/TestScreenModel.h"
#include "controllers/TestScreenController.h"

TestScreen::TestScreen(QQmlContext* ctxt) {
    registerScreen(ctxt);
}

void TestScreen::registerScreen(QQmlContext* ctxt) {
    ctxt->setContextProperty("TestScreenController", new TestScreenController());
    ctxt->setContextProperty("TestScreenModel", new TestScreenModel());
}
