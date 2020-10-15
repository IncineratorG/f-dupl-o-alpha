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
    common/libs/redux/state/StatePropIdsGenerator.cpp \
    utils/common/localization/Localization.cpp \
    native-screens/duplicates/DuplicatesScreen.cpp \
    native-screens/duplicates/controllers/DuplicatesScreenController.cpp \
    stores/states/input-folders-list/InputFoldersListState.cpp \
    stores/reducers/input-folders-list/InputFoldersListReducer.cpp \
    stores/action-types/input-folders-list/InputFoldersListActionTypes.cpp \
    stores/states/system/SystemState.cpp \
    stores/reducers/system/SystemReducer.cpp \
    stores/action-types/system/SystemActionTypes.cpp \
    common/libs/native-component/NativeComponent.cpp \
    native-screens/duplicates/models/DuplicatesScreenModel.cpp \
    stores/actions/input-folders-list/InputFoldersListActions.cpp \
    native-components/specific/duplicates/input-folders-list/InputFoldersListComponent.cpp \
    native-components/specific/duplicates/input-folders-list/models/InputFoldersListModel.cpp \
    stores/states/duplicates-finder/DuplicatesFinderState.cpp \
    stores/reducers/duplicates-finder/DuplicatesFinderReducer.cpp \
    stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.cpp \
    stores/actions/duplicates-finder/DuplicatesFinderActions.cpp \
    common/libs/service/Service.cpp \
    services/Services.cpp \
    services/duplicates-finder/DuplicatesFinderService.cpp \
    stores/middleware/duplicates-finder/DuplicatesFinderMiddleware.cpp \
    services/duplicates-finder/pipeline/DuplicatesFinderPipeline.cpp \
    utils/common/notifier/Notifier.cpp \
    services/duplicates-finder/event-types/DuplicatesFinderServiceEventTypes.cpp \
    stores/middleware/duplicates-finder/DuplicatesFinderEventsMiddleware.cpp \
    common/libs/operation/Operation.cpp \
    common/libs/operation/PipelineOperation.cpp \
    services/duplicates-finder/pipeline/operations/wait/WaitOperation.cpp \
    services/duplicates-finder/pipeline/operations-sequence/OperationsSequence.cpp \
    services/duplicates-finder/pipeline/operations-transition/OperationsTransition.cpp \
    services/duplicates-finder/data/input-path/InputPath.cpp \
    native-components/specific/duplicates/input-folders-list/models/InputFoldersWithSubpathsListModel.cpp \
    services/duplicates-finder/pipeline/operations/extract-files-info/ExtractFilesInfoOperation.cpp \
    services/duplicates-finder/data/file-info/FileInfo.cpp \
    services/duplicates-finder/pipeline/operations/find-file-duplicates/FindFileDuplicatesOperation.cpp

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
    common/libs/redux/state/StatePropIdsGenerator.h \
    utils/common/localization/Localization.h \
    native-screens/duplicates/DuplicatesScreen.h \
    native-screens/duplicates/controllers/DuplicatesScreenController.h \
    stores/states/input-folders-list/InputFoldersListState.h \
    stores/reducers/input-folders-list/InputFoldersListReducer.h \
    stores/action-types/input-folders-list/InputFoldersListActionTypes.h \
    stores/states/system/SystemState.h \
    stores/reducers/system/SystemReducer.h \
    stores/action-types/system/SystemActionTypes.h \
    common/libs/native-component/NativeComponent.h \
    native-screens/duplicates/models/DuplicatesScreenModel.h \
    stores/actions/input-folders-list/InputFoldersListActions.h \
    native-components/specific/duplicates/input-folders-list/InputFoldersListComponent.h \
    native-components/specific/duplicates/input-folders-list/models/InputFoldersListModel.h \
    stores/states/duplicates-finder/DuplicatesFinderState.h \
    stores/reducers/duplicates-finder/DuplicatesFinderReducer.h \
    stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h \
    stores/actions/duplicates-finder/DuplicatesFinderActions.h \
    common/libs/service/Service.h \
    services/Services.h \
    services/duplicates-finder/DuplicatesFinderService.h \
    stores/middleware/duplicates-finder/DuplicatesFinderMiddleware.h \
    services/duplicates-finder/pipeline/DuplicatesFinderPipeline.h \
    utils/common/notifier/Notifier.h \
    services/duplicates-finder/event-types/DuplicatesFinderServiceEventTypes.h \
    stores/middleware/duplicates-finder/DuplicatesFinderEventsMiddleware.h \
    common/libs/operation/Operation.h \
    common/libs/operation/PipelineOperation.h \
    services/duplicates-finder/pipeline/operations/wait/WaitOperation.h \
    services/duplicates-finder/pipeline/operations-sequence/OperationsSequence.h \
    services/duplicates-finder/pipeline/operations-transition/OperationsTransition.h \
    services/duplicates-finder/data/input-path/InputPath.h \
    native-components/specific/duplicates/input-folders-list/models/InputFoldersWithSubpathsListModel.h \
    services/duplicates-finder/pipeline/operations/extract-files-info/ExtractFilesInfoOperation.h \
    services/duplicates-finder/data/file-info/FileInfo.h \
    services/duplicates-finder/pipeline/operations/find-file-duplicates/FindFileDuplicatesOperation.h

