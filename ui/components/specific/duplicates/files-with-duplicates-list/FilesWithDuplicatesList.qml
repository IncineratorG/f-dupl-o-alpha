import QtQuick 2.12
import QtQuick.Controls 1.4

import "./files-with-duplicates-list-item"

Item {
    ListView {
        anchors.fill: parent

        clip: true

        model: FilesWithDuplicatesListModel

        delegate: FilesWithDuplicatesListItem {
            width: parent.width
            height: 30
        }
    }
}
