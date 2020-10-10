#ifndef DUPLICATESSCREEN_H
#define DUPLICATESSCREEN_H

#include "common/libs/native-screen/NativeScreen.h"

class DuplicatesScreen : public NativeScreen
{
public:
    DuplicatesScreen(QQmlContext* ctxt);

    void registerScreen(QQmlContext* ctxt);
};

#endif // DUPLICATESSCREEN_H
