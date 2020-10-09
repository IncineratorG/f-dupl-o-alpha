QT += quick
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    common/libs/native-screen/NativeScreen.cpp \
    native-screens/test/TestScreen.cpp \
    native-screens/test/controllers/TestScreenController.cpp \
    native-screens/test/models/TestScreenModel.cpp \
    common/libs/redux/state/State.cpp \
    common/libs/redux/selector/Selector.cpp \
    common/libs/redux/prop/StateProp.cpp \
    common/libs/redux/prop/StatePropLike.cpp \
    stores/states/test/TestState.cpp \
    stores/AppStore.cpp \
    common/libs/redux/action/Action.cpp \
    common/libs/redux/payload/Payload.cpp \
    common/libs/redux/reducer/Reducer.cpp \
    common/libs/redux/store/Store.cpp \
    stores/reducers/test/TestReducer.cpp \
    common/libs/redux/middleware/Middleware.cpp \
    common/libs/redux/middleware/EventsMiddleware.cpp \
    stores/middleware/test/TestMiddleware.cpp \
    stores/middleware/test/TestEventsMiddleware.cpp \
    stores/middleware/RootMiddleware.cpp \
    stores/actions/test/TestActions.cpp \
    stores/action-types/test/TestActionTypes.cpp \
    common/libs/redux/selector/SelectorIdsGenerator.cpp \
    common/libs/redux/state/StatePropIdsGenerator.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    common/libs/native-screen/NativeScreen.h \
    native-screens/test/TestScreen.h \
    native-screens/test/controllers/TestScreenController.h \
    native-screens/test/models/TestScreenModel.h \
    common/libs/redux/state/State.h \
    common/libs/redux/selector/Selector.h \
    common/libs/redux/prop/StateProp.h \
    common/libs/redux/prop/StatePropLike.h \
    stores/states/test/TestState.h \
    stores/AppStore.h \
    common/libs/redux/action/Action.h \
    common/libs/redux/payload/Payload.h \
    common/libs/redux/reducer/Reducer.h \
    common/libs/redux/store/Store.h \
    stores/reducers/test/TestReducer.h \
    common/libs/redux/middleware/Middleware.h \
    common/libs/redux/middleware/EventsMiddleware.h \
    stores/middleware/test/TestMiddleware.h \
    stores/middleware/test/TestEventsMiddleware.h \
    stores/middleware/RootMiddleware.h \
    stores/actions/test/TestActions.h \
    stores/action-types/test/TestActionTypes.h \
    common/libs/redux/selector/SelectorIdsGenerator.h \
    common/libs/redux/state/StatePropIdsGenerator.h
