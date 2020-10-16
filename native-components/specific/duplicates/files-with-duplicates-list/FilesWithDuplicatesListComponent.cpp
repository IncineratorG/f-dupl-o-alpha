#include "FilesWithDuplicatesListComponent.h"
#include "native-components/specific/duplicates/files-with-duplicates-list/models/FilesWithDuplicatesListModel.h"

FilesWithDuplicatesListComponent::FilesWithDuplicatesListComponent(QQmlContext* ctxt) {
    registerComponent(ctxt);
}

void FilesWithDuplicatesListComponent::registerComponent(QQmlContext* ctxt) {
    ctxt->setContextProperty("FilesWithDuplicatesListModel", new FilesWithDuplicatesListModel());
}
