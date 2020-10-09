#ifndef TESTSCREEN_H
#define TESTSCREEN_H

#include "common/libs/native-screen/NativeScreen.h"

class TestScreen : public NativeScreen
{
public:
    TestScreen(QQmlContext* ctxt);

    void registerScreen(QQmlContext* ctxt);
};

#endif // TESTSCREEN_H
