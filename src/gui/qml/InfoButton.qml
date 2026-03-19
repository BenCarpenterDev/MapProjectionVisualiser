import QtQuick
import QtQuick.Controls.Basic

Rectangle {
    id: infoButton
    anchors.bottom: parent.bottom
    anchors.right: parent.right
    anchors.rightMargin: 30
    anchors.bottomMargin: 30
    radius: 8
    width: 44
    height: width
    color: Qt.rgba(0, 0, 0, hoverHandler.hovered ? 0.21 : 0.07)

    Text {
        anchors.centerIn: parent
        text: 'i'
        font.family: "Helvetica"
        font.pointSize: 20
        font.bold: true
        color: "white"
    }

    HoverHandler {
        id: hoverHandler
    }

    TapHandler {
        onTapped: (eventPoint, button) => {
            infoPanel.stateVisible = !infoPanel.stateVisible
        }
    }
}