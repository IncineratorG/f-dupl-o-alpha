#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QList>

#include "native-screens/test/TestScreen.h"
#include "native-screens/duplicates/DuplicatesScreen.h"
#include "utils/common/localization/Localization.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    auto localization = new Localization(&engine);
    engine.rootContext()->setContextProperty("l", localization);

    QList<NativeScreen*> nativeScreens({
                                           new TestScreen(engine.rootContext()),
                                           new DuplicatesScreen(engine.rootContext())
                                       });

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
