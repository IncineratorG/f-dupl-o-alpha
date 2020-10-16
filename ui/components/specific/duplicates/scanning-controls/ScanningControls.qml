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

            text: ScanningControllsModel.duplicatesServiceRunning ?
                  l.t("ScanningControls_toggleScanningButton_stopScanning") :
                  l.t("ScanningControls_toggleScanningButton_startScanning")

            onClicked: {
                if (ScanningControllsModel.duplicatesServiceRunning) {
                    ScanningControllsController.stopScanningButtonHandler()
                } else {
                    ScanningControllsController.startScanningButtonHandler()
                }
            }
        }
    }
}
