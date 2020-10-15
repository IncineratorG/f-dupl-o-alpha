#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QList>

#include "services/Services.h"
#include "services/duplicates-finder/data/input-path/InputPath.h"
#include "services/duplicates-finder/data/duplicates-list/DuplicatesList.h"
#include "utils/common/localization/Localization.h"
#include "native-screens/test/TestScreen.h"
#include "native-screens/duplicates/DuplicatesScreen.h"
#include "native-components/specific/duplicates/input-folders-list/InputFoldersListComponent.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qRegisterMetaType<QList<InputPath>>("QList<InputPath>");
    qRegisterMetaType<DuplicatesList>("DuplicatesList");

    auto localization = Localization::createAndGet(&engine);
    engine.rootContext()->setContextProperty("l", localization);

    QList<NativeScreen*> nativeScreens({
        new TestScreen(engine.rootContext()),
        new DuplicatesScreen(engine.rootContext())
    });

    QList<NativeComponent*> nativeComponents({
        new InputFoldersListComponent(engine.rootContext()),
    });

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
