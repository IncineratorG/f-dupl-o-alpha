#include "ScanningControlsComponent.h"
#include "native-components/specific/duplicates/scanning-controls/controllers/ScanningControllsController.h"
#include "native-components/specific/duplicates/scanning-controls/models/ScanningControllsModel.h"

ScanningControlsComponent::ScanningControlsComponent(QQmlContext* ctxt) {
    registerComponent(ctxt);
}

void ScanningControlsComponent::registerComponent(QQmlContext* ctxt) {
    ctxt->setContextProperty("ScanningControllsController", new ScanningControllsController());
    ctxt->setContextProperty("ScanningControllsModel", new ScanningControllsModel());
}
