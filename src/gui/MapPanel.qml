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
    height: 160
    color: Qt.rgba(0, 0, 0, 0.21)

    property bool gridEnabled: gridToggle.checked

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
                mainWindow.backgroundColour = "#9FCBF9"
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: mapTwo
            text: "Pangaea"
            onClicked: {
                converter.selectMap("preHistoricMap")
                mainWindow.backgroundColour = "#9FCBF9"
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: mapThree
            text: "Shapes"
            onClicked: {
                converter.selectMap("shapesMap")
                mainWindow.backgroundColour = "#9FCBF9"
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: mapFour
            text: "Mars TES Albedo"
            onClicked: {
                converter.selectMap("marsMap")
                mainWindow.backgroundColour = "#8c7bbf"
                parent.resetColours()
                this.state = "Selected"
            }
        }
        CheckBox {
            id: gridToggle
            text: qsTr("Graticules Grid")
        }

        Component.onCompleted: {
            mapOne.state = "Selected"
        }
    }
}