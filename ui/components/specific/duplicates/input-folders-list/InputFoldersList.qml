import QtQuick 2.12
import QtQuick.Controls 1.4

import "./input-folders-list-item"

Item {
    ListView {
        id: listView

        anchors.fill: parent
        anchors.margins: 4

        clip: true

        model: InputFoldersListModel

        delegate: InputFoldersListItem {
            width: parent.width
            height: 30
        }
    }
}
