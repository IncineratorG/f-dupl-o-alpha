#include "InputFoldersComponent.h"
#include "native-components/specific/duplicates/input-folders/models/InputFoldersListModel.h"
#include "native-components/specific/duplicates/input-folders/controllers/InputFoldersController.h"

InputFoldersComponent::InputFoldersComponent(QQmlContext* ctxt) {
    registerComponent(ctxt);
}

void InputFoldersComponent::registerComponent(QQmlContext* ctxt) {
    ctxt->setContextProperty("InputFoldersListModel", new InputFoldersListModel());
    ctxt->setContextProperty("InputFoldersController", new InputFoldersController());
}
