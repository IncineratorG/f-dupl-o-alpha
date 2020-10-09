#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QList>

#include "native-screens/test/TestScreen.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QList<NativeScreen*> nativeScreens({
                                           new TestScreen(engine.rootContext())
                                       });

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
