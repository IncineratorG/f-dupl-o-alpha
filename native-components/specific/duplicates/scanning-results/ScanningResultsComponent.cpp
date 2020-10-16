#include "ScanningResultsComponent.h"
#include "native-components/specific/duplicates/scanning-results/models/ScanningResultsFilesWithDuplicatesListModel.h"
#include "native-components/specific/duplicates/scanning-results/controllers/ScanningResultsController.h"

ScanningResultsComponent::ScanningResultsComponent(QQmlContext* ctxt) {
    registerComponent(ctxt);
}

void ScanningResultsComponent::registerComponent(QQmlContext* ctxt) {
    ctxt->setContextProperty("ScanningResultsController", new ScanningResultsController());
    ctxt->setContextProperty("FilesWithDuplicatesListModel", new ScanningResultsFilesWithDuplicatesListModel());
}
