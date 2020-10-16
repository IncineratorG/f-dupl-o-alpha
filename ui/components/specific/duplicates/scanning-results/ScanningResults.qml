import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

import "../files-with-duplicates"

Rectangle {
    border.color: 'lightgrey'
    border.width: 1

    SplitView {
        anchors.fill: parent

        orientation: Qt.Vertical

        handleDelegate: Item {width: 3}

        Item {
            id: filesWithDuplicatesListContainer

            Layout.fillHeight: true
            Layout.minimumHeight: 20

            FilesWithDuplicates {
                anchors.fill: parent
            }
        }

        Rectangle {
            id: fileDuplicatesListContainer

            height: 50
            Layout.minimumHeight: 20

            color: 'green'
        }
    }
}
