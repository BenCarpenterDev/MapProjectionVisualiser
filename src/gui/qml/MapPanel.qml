import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: mapPanel
    anchors.bottom: parent.bottom
    anchors.left: parent.left
    anchors.leftMargin: 30
    anchors.bottomMargin: 30
    radius: 8
    width: 140
    height: 140
    color: Qt.rgba(0, 0, 0, 0.21)

    ColumnLayout {
        anchors.centerIn: parent

        function resetColours(){
            mapOne.state = "Unselected"
            mapTwo.state = "Unselected"
            mapThree.state = "Unselected"
            mapFour.state = "Unselected"
        }

        OptionsButtons {
            id: mapOne
            text: "World Map"
            onClicked: {
                converter.selectMap("worldMap")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: mapTwo
            text: "Grid"
            onClicked: {
                converter.selectMap("gridMap")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: mapThree
            text: "Pangaea Map"
            onClicked: {
                converter.selectMap("preHistoricMap")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: mapFour
            text: "Placeholder 4"
            onClicked: {
                //converter.selectProjection("winkelTripel")
                parent.resetColours()
                this.state = "Selected"
            }
        }

        Component.onCompleted: {
            mapOne.state = "Selected"
        }
    }
}