import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: optionsPanel
    anchors.top: parent.top
    anchors.right: parent.right
    anchors.rightMargin: 30
    anchors.topMargin: 30
    radius: 8
    width: 240
    height: width*2
    color: Qt.rgba(0, 0, 0, 0.21)

    Text{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        text: "Placeholder Title"
        font.family: "Helvetica"
        font.pointSize: 20
        color: "red"
    }

    Text {
        anchors.centerIn: parent
        width: parent.width - 20
        wrapMode: Text.WordWrap
        text: "Placeholder Info Placeholder Info Placeholder Info Placeholder Info Placeholder Info"
        font.family: "Helvetica"
        font.pointSize: 18
        color: "red"
    }
}