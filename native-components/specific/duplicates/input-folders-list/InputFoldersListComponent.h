#ifndef INPUTFOLDERSLISTCOMPONENT_H
#define INPUTFOLDERSLISTCOMPONENT_H

#include "common/libs/native-component/NativeComponent.h"

class InputFoldersListComponent : public NativeComponent
{
public:
    InputFoldersListComponent(QQmlContext *ctxt);

    void registerComponent(QQmlContext *ctxt);
};

#endif // INPUTFOLDERSLISTCOMPONENT_H
