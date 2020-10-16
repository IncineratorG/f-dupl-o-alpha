#ifndef SCANNINGCONTROLSCOMPONENT_H
#define SCANNINGCONTROLSCOMPONENT_H

#include "common/libs/native-component/NativeComponent.h"

class ScanningControlsComponent : public NativeComponent
{
public:
    ScanningControlsComponent(QQmlContext* ctxt);

    void registerComponent(QQmlContext* ctxt);
};

#endif // SCANNINGCONTROLSCOMPONENT_H
