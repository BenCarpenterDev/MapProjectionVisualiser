import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: infoPanel
    property bool stateVisible: false
    property string contentProjection

    anchors.top: parent.top
    anchors.right: parent.right
    anchors.rightMargin: 30
    anchors.topMargin: 30
    radius: 8
    width: 240
    height: width*2
    color: Qt.rgba(0, 0, 0, 0.21)

    InfoContent{}

    states: [
        State { when: stateVisible;
            PropertyChanges {   target: infoPanel; opacity: 1.0    }
        },
        State { when: !stateVisible;
            PropertyChanges {   target: infoPanel; opacity: 0.0    }
        }
    ]

    transitions: Transition {
        NumberAnimation { property: "opacity"; duration: 500}
    }
}