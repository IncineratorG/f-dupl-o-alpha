import QtQuick 2.0

import "../../components/specific/duplicates/input-folders"

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
        id: scanningResultContainer

        anchors.top: inputFoldersContainer.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        color: 'blue'
    }
}
