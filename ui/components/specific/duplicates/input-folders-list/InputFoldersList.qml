import QtQuick 2.12
import QtQuick.Controls 1.4

import "./input-folders-list-item"

Rectangle {
    color: 'transparent'

    ListView {
        id: listView

        anchors.fill: parent
        anchors.margins: 4

        clip: true

        spacing: 4

        model: InputFoldersListModel

        delegate: InputFoldersListItem {
            width: parent.width
            height: 30
        }
    }
}
