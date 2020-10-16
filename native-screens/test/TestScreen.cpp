#include "TestScreen.h"
#include "models/TestScreenModel.h"
#include "controllers/TestScreenController.h"

TestScreen::TestScreen(QQmlContext* ctxt) {
    registerScreen(ctxt);
    registerComponents(ctxt);
}

void TestScreen::registerScreen(QQmlContext* ctxt) {
    ctxt->setContextProperty("TestScreenController", new TestScreenController());
    ctxt->setContextProperty("TestScreenModel", new TestScreenModel());
}

void TestScreen::registerComponents(QQmlContext* ctxt) {

}
