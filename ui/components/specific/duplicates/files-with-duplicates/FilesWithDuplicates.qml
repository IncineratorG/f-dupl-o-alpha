import QtQuick 2.0

import "../files-with-duplicates-list"

Item {
    Rectangle {
        id: filesWithDuplicatesListContainer

        anchors.fill: parent
        anchors.margins: 4

        border.width: 1
        border.color: 'lightgrey'

        color: 'transparent'

        FilesWithDuplicatesList {
            anchors.fill: parent
        }
    }
}
