import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    color: 'grey'

    Rectangle {
        id: toggleScanningButtonContainer

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 40

        color: 'transparent'

        Button {
            id: toggleScanningButton

            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 4

            text: l.t("ScanningControls_toggleScanningButton_startScanning")

            onClicked: {
                DuplicatesScreenController.startScanningButtonHandler()
            }
        }
    }
}
