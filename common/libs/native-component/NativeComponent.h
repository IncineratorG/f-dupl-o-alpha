#ifndef NATIVECOMPONENT_H
#define NATIVECOMPONENT_H

#include <QQmlContext>

class NativeComponent
{
public:
    virtual ~NativeComponent() = 0;

    virtual void registerComponent(QQmlContext* ctxt) = 0;
};

#endif // NATIVECOMPONENT_H
