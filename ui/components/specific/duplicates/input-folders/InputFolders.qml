import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3

import "../input-folders-list"

Item {
    Rectangle {
        id: inputFoldersListContainer

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: buttonsContainer.left
        anchors.topMargin: 4
        anchors.bottomMargin: 4
        anchors.leftMargin: 4

        border.width: 1
        border.color: 'lightgrey'

        InputFoldersList {
            anchors.fill: parent
        }
    }

    Item {
        id: buttonsContainer

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        width: 100

        Item {
            id: buttonsInnerContainer

            anchors.fill: parent
            anchors.margins: 4

            Button {
                id: addFolderButton

                anchors.centerIn: parent

                text: l.t("InputFolders_addFolderButton")

                onClicked: {
                    fileDialog.open()
                }
            }
        }
    }

    FileDialog {
        id: fileDialog

        visible: false

        selectFolder: true

        title: l.t("InputFolders_fileDialogTitle")

        onAccepted: {
            DuplicatesScreenController.addFolderHandler(fileDialog.fileUrls)
        }
    }
}
