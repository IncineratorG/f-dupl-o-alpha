#ifndef SCANNINGRESULTSCOMPONENT_H
#define SCANNINGRESULTSCOMPONENT_H

#include "common/libs/native-component/NativeComponent.h"

class ScanningResultsComponent : public NativeComponent
{
public:
    ScanningResultsComponent(QQmlContext* ctxt);

    void registerComponent(QQmlContext* ctxt);
};

#endif // SCANNINGRESULTSCOMPONENT_H
