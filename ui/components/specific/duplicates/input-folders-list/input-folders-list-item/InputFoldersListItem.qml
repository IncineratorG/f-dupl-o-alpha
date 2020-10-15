import QtQuick 2.0

Rectangle {
    color: index % 2 === 0 ? 'white' : 'lightgrey'

    border.width: 1
    border.color: 'lightgrey'

    Item {
        id: folderNameContainer

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: controlButtonsContainer.left

        Text {
            anchors.left: parent.left
            anchors.leftMargin: 4
            anchors.verticalCenter: parent.verticalCenter

            width: parent.width

            text: folderName
            elide: Text.ElideMiddle
            font.pointSize: 11

            color: "black"
        }
    }

    Item {
        id: controlButtonsContainer

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 4

        width: 100

        Rectangle {
            id: includeSubpathIndicator

            width: 20
            height: 20

            border.width: 1
            border.color: "green"

            color: includeSubpath ? "green" : "white"

            anchors.verticalCenter: parent.verticalCenter
            anchors.right: removeButton.left
            anchors.rightMargin: 4

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    DuplicatesScreenController.setIncludeFolderSubpaths(folderName, !includeSubpath)
                }
            }
        }

        Rectangle {
            id: removeButton

            width: 20
            height: 20

            color: 'red'

            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right

//            anchors.centerIn: parent

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    DuplicatesScreenController.removeFolderButtonHandler(folderName)
                }
            }
        }
    }
}
