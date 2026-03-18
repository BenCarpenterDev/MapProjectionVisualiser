import QtQuick
import QtQuick.Controls.Basic

Button {
    id: control
    property string stateColour: "#f2f2f2"
    property string stateTextColour: "#2f4858"

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#33658a" : stateTextColour
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 120
        implicitHeight: 10
        color: stateColour
        opacity: enabled ? 1 : 0.3
        border.color: control.down ? "#33658a" : stateTextColour
        border.width: 1
        radius: 2
    }

    states: [
        State {
            name: "Selected"
            PropertyChanges { target: control; stateColour: "#808080"; stateTextColour: "#f2f2f2" }
        },
        State {
            name: "Unselected"
            PropertyChanges { target: control; stateColour: "#f2f2f2"; stateTextColour: "#2f4858" }
        }
    ]

}