#ifndef INPUTFOLDERSCOMPONENT_H
#define INPUTFOLDERSCOMPONENT_H

#include "common/libs/native-component/NativeComponent.h"

class InputFoldersComponent : public NativeComponent
{
public:
    InputFoldersComponent(QQmlContext* ctxt);

    void registerComponent(QQmlContext* ctxt);
};

#endif // INPUTFOLDERSCOMPONENT_H
