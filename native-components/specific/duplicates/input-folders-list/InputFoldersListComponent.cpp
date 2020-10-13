#include "InputFoldersListComponent.h"
#include "native-components/specific/duplicates/input-folders-list/models/InputFoldersListModel.h"
#include "native-components/specific/duplicates/input-folders-list/models/InputFoldersWithSubpathsListModel.h"

InputFoldersListComponent::InputFoldersListComponent(QQmlContext *ctxt) {
    registerComponent(ctxt);
}

void InputFoldersListComponent::registerComponent(QQmlContext* ctxt) {
    ctxt->setContextProperty("InputFoldersListModel", new InputFoldersWithSubpathsListModel());
}
