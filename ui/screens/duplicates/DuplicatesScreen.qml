import QtQuick 2.0

import "../../components/specific/duplicates/input-folders"
import "../../components/specific/duplicates/scanning-results"
import "../../components/specific/duplicates/scanning-controls"

Rectangle {
    Item {
        id: inputFoldersContainer

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: parent.width / 8

        InputFolders {
            anchors.fill: parent
        }
    }

    Rectangle {
        id: workZoneContainer

        anchors.top: inputFoldersContainer.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        color: 'blue'

        Item {
            id: resultListContainer

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: controlsContainer.left

            ScanningResults {
                anchors.fill: parent
            }
        }

        Item {
            id: controlsContainer

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: 100

            ScanningControls {
                anchors.fill: parent
            }
        }
    }
}
