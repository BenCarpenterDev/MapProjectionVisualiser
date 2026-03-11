import QtQuick
import QtQuick.Controls.Basic

Button {
    id: control

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#33658a" : "#2f4858"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 110
        implicitHeight: 10
        opacity: enabled ? 1 : 0.3
        border.color: control.down ? "#33658a" : "#2f4858"
        border.width: 1
        radius: 2
    }
}