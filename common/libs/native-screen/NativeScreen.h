#ifndef NATIVESCREEN_H
#define NATIVESCREEN_H

#include "common/libs/native-component/NativeComponent.h"

#include <QQmlContext>
#include <QList>

class NativeScreen
{
public:
    virtual ~NativeScreen() = 0;

protected:
    virtual void registerScreen(QQmlContext* ctxt) = 0;
    virtual void registerComponents(QQmlContext* ctxt) = 0;
};

#endif // NATIVESCREEN_H
