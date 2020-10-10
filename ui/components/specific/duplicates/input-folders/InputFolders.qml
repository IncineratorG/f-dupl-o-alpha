import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

import "../input-folders-list"

Item {
    Item {
        id: inputFoldersListContainer

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: buttonsContainer.left

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

                anchors.left: parent.left
                anchors.right: parent.right

                text: l.t("InputFolders_addFolderButton")

                onClicked: {
                    DuplicatesScreenController.addFolderButtonHandler()
                }
            }

            Button {
                id: removeFolderButton

                anchors.top: addFolderButton.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 4

                text: l.t("InputFolders_removeFolderButton")

                onClicked: {
                    DuplicatesScreenController.removeFolderButtonHandler()
                }
            }
        }
    }
}
