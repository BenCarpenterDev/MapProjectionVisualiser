import QtQuick
import QtQuick.Shapes
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.VectorImage
import GeoJsonConverter

Window {
    id: mainWindow

    title: qsTr("World")
    width: 1920
    height: 1080
    visible: true
    visibility: Window.Maximized
    color: "white"

    MenuBar {// currently not visible, needs an custom item visual to be shown
        Menu {
            title: ("Projections")
            Action { 
                text: "WGS84"
                onTriggered: {
                    converter.convertFile("wgs84")
                    console.log("WGS84 projection selected")
                }
            }
            Action { 
                text: "Web Mercator"
                onTriggered: {
                    converter.convertFile("webMercator")
                    console.log("Web Mercator projection selected")
                }
            }
            Action { 
                text: "Gall Stereographic"
                onTriggered: {
                    converter.convertFile("gallStereographic")
                    console.log("Gall Stereographic projection selected")
                }
            }
        }
    }

    GeoJsonConverter {
        id: converter

       Component.onCompleted: {
            converter.convertFile("webMercator")
        }

        onSvgSignal: (filePath) => {
            console.log("SVG signal recieved with file path: " + filePath)
            worldMap.source = filePath
        }
    }

    Rectangle {
        id: bgFill
        color: "#9FCBF9"
        anchors.fill: parent
    
        VectorImage {
            id: worldMap
            scale: 1.0
            width: mainWindow.sourceSize
            height: mainWindow.sourceSize
            preferredRendererType: VectorImage.CurveRenderer
            anchors.centerIn: parent
        }
    }
}
