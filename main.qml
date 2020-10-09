import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "ui/components/common/coordinators/main-cooridnator"

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("FDuplO")

    MainCoordinator {
        anchors.fill: parent
    }
}
