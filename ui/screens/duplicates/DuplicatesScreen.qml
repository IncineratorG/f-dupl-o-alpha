import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

import "../../components/specific/duplicates/input-folders"
import "../../components/specific/duplicates/scanning-results"
import "../../components/specific/duplicates/scanning-controls"

Rectangle {
//    Rectangle {
//        id: testRect

//        anchors.fill: parent

//        color: "#cc000000"

//        z: 1
//        visible: DuplicatesScreenModel.duplicatesServiceRunning

//        MouseArea {
//            anchors.fill: parent
//        }
//    }

    SplitView {
        anchors.fill: parent

        orientation: Qt.Vertical

        handleDelegate: Item {width: 3}

        Item {
            id: inputFoldersContainer

            Layout.minimumHeight: 100

            height: parent.width / 8

            InputFolders {
                anchors.fill: parent
            }
        }

        Item {
            id: workZoneContainer

            Layout.fillHeight: true
            Layout.minimumHeight: 100

            SplitView {
                anchors.fill: parent

                orientation: Qt.Horizontal

                handleDelegate: Item {width: 3}

                Item {
                    id: resultListContainer

                    Layout.fillWidth: true
                    Layout.minimumWidth: 100

                    ScanningResults {
                        anchors.fill: parent
                    }
                }

                Item {
                    id: controlsContainer

                    Layout.minimumWidth: 100

                    ScanningControls {
                        anchors.fill: parent
                    }
                }
            }
        }
    }
}
