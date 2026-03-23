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
    height: 240
    color: Qt.rgba(0, 0, 0, 0.21)

    ColumnLayout {
        anchors.centerIn: parent

        function resetColours(){
            projOne.state = "Unselected"
            projTwo.state = "Unselected"
            projThree.state = "Unselected"
            projFour.state = "Unselected"
            projFive.state = "Unselected"
            projSix.state = "Unselected"
            projSeven.state = "Unselected"
        }

        OptionsButtons {
            id: projOne
            text: "WGS84"
            onClicked: {
                converter.selectProjection("wgs84")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: projTwo
            text: "Web Mercator"
            onClicked: {
                converter.selectProjection("webMercator")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: projThree
            text: "Gall Stereographic"
            onClicked: {
                converter.selectProjection("gallStereographic")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: projFour
            text: "Winkel Tripel"
            onClicked: {
                converter.selectProjection("winkelTripel")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: projFive
            text: "Gall Peters"
            onClicked: {
                converter.selectProjection("gallPeters")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: projSix
            text: "Sinusoidal"
            onClicked: {
                converter.selectProjection("sinusoidal")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        OptionsButtons {
            id: projSeven
            text: "Equal Earth"
            onClicked: {
                converter.selectProjection("equalEarth")
                parent.resetColours()
                this.state = "Selected"
            }
        }
        //OptionsButtons {
        //    text: "Azimuthal Equidistant"
        //    onClicked: {
        //        converter.selectProjection("azimuthalEquidistant")
        //    }
        //}

        Component.onCompleted: {
            projTwo.state = "Selected"
        }
    }
}