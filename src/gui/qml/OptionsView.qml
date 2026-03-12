import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: optionsPanel
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.leftMargin: 30
    anchors.topMargin: 30
    radius: 8
    width: 140
    height: width
    color: Qt.rgba(0, 0, 0, 0.21)

    ColumnLayout {
        anchors.centerIn: parent

        OptionsButtons {
            text: "WGS84"
            onClicked: {
                converter.convertFile("wgs84")
            }
        }
        OptionsButtons {
            text: "Web Mercator"
            onClicked: {
                converter.convertFile("webMercator")
            }
        }
        OptionsButtons {
            text: "Gall Stereographic"
            onClicked: {
                converter.convertFile("gallStereographic")
            }
        }
        OptionsButtons {
            text: "Winkel Tripel"
            onClicked: {
                converter.convertFile("winkelTripel")
            }
        }
        OptionsButtons {
            text: "Equirectangular"
            onClicked: {
                converter.convertFile("equirectangular")
            }
        }
    }
}