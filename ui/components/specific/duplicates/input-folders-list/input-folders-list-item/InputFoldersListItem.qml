import QtQuick 2.0

Rectangle {
    color: 'lightblue'

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
            font.pointSize: 12

            color: "black"
        }
    }

    Item {
        id: controlButtonsContainer

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        width: 50

        Rectangle {
            id: removeButton

            width: 20
            height: 20

            color: 'red'

            anchors.centerIn: parent

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    DuplicatesScreenController.removeFolderButtonHandler(folderName)
                }
            }
        }
    }
}
