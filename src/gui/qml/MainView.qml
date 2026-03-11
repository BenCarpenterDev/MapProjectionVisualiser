import QtQuick
import QtQuick.Shapes
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.VectorImage
import GeoJsonConverter

Window {
    id: mainWindow
    title: qsTr("MapProjectionVisualiser")
    width: 1920
    height: 1080
    visible: true
    visibility: Window.Maximized
    color: "white"

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
            assumeTrustedSource: true
        }

        OptionsView{}
        
        InfoBox{
             id: infoPanel
             visible: false
        }

        Rectangle {
            id: gear
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: 30
            anchors.bottomMargin: 30
            radius: 8
            width: 44
            height: width
            color: Qt.rgba(0, 0, 0, hoverHandler.hovered ? 0.21 : 0.07)

            HoverHandler {
                id: hoverHandler
            }

            TapHandler {
                onTapped: (eventPoint, button) => {
                  infoPanel.visible = !infoPanel.visible
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.NoButton
            
            onWheel: (wheel) => {
                const zoomFactor = 1.1
                const oldScale = worldMap.scale
                
                if (wheel.angleDelta.y > 0) {
                    worldMap.scale = Math.min(oldScale * zoomFactor, 10.0)
                } else {
                    worldMap.scale = Math.max(oldScale / zoomFactor, 1.0)
                }
            }
        }

    }
}
