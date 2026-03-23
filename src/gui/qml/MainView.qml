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
    color: "#9FCBF9"

    GeoJsonConverter {
        id: converter

       Component.onCompleted: {
            converter.selectMap("worldMap")
            converter.selectProjection("webMercator")
        }

        onSvgSignal: (filePath) => {
            console.log("SVG signal recieved with file path: " + filePath)
            worldMap.source = filePath
        }

        onProjectionChanged: (projection) => {
            infoPanel.contentProjection = projection
        }
    }

    Rectangle {
        id: worldMapContainer
        width: parent.width
        height: parent.height
        color: "#9FCBF9"

        x: (parent.width  - width)  / 2
        y: (parent.height - height) / 2
    
        VectorImage {
            id: worldMap
            width: mainWindow.sourceSize
            height: mainWindow.sourceSize
            preferredRendererType: VectorImage.CurveRenderer
            anchors.centerIn: parent
            assumeTrustedSource: true
        }

        transform: Scale {
            id: mapScale
            origin.x: pinchArea.nextX
            origin.y: pinchArea.nextY
            xScale: pinchArea.nextScale
            yScale: pinchArea.nextScale
        }

        PinchArea {
            id: pinchArea
            anchors.fill: parent
            property real prevX: 0 // old x of area
            property real prevY: 0 // old y of area
            property real nextX: 0 // new x based on cursor position
            property real nextY: 0 // new y based on cursor position
            property real prevScale: 1 // previous/current scale
            property real nextScale: 1 // new scale to apply
            property real maxScale: 10 // how zoomed in
            property real minScale: 1 // how zoomed out

            onPinchUpdated: {                        
                prevScale = mapScale.xScale
                var incrementScale = pinch.scale-pinch.previousScale
                var newZoom = prevScale+incrementScale

                if (newZoom <= maxScale && newZoom >= minScale) { // doesn't go out of min and max scale
                    nextScale = newZoom
                }
            }                 

            MouseArea {
                id: dragArea
                hoverEnabled: true
                anchors.fill: parent
                drag.target: worldMapContainer            
                scrollGestureEnabled: false 

                onWheel: (wheel) => {                           
                    pinchArea.prevX = mapScale.origin.x
                    pinchArea.prevY = mapScale.origin.y
                    pinchArea.prevScale = mapScale.xScale

                    pinchArea.nextX = mouseX
                    pinchArea.nextY = mouseY
            
                    var newZoom
                    if (wheel.angleDelta.y > 0) {
                        newZoom = pinchArea.prevScale+0.2
                        if (newZoom <= pinchArea.maxScale) {
                            pinchArea.nextScale = newZoom
                        } else {
                            pinchArea.nextScale = pinchArea.maxScale
                        }
                    } else {
                        newZoom = pinchArea.prevScale-0.2
                        if (newZoom >= pinchArea.minScale) {
                            pinchArea.nextScale = newZoom
                        } else {
                            pinchArea.nextScale = pinchArea.minScale
                        }
                    }
                    // object x and y need to change, so scale is focused on new "center" coordinates
                    
                    if (pinchArea.nextScale == 1) {
                        worldMapContainer.x = (mainWindow.width  - worldMapContainer.width)  / 2
                        worldMapContainer.y = (mainWindow.height - worldMapContainer.height) / 2
                    } 
                    else {
                        worldMapContainer.x = worldMapContainer.x + (pinchArea.prevX-pinchArea.nextX)*(1-pinchArea.prevScale)
                        worldMapContainer.y = worldMapContainer.y + (pinchArea.prevY-pinchArea.nextY)*(1-pinchArea.prevScale)
                    }
                }                        
            }
        }
    }

    ProjectionsView{}
    
    InfoBox{
        id: infoPanel
        opacity: 0.0
    }

    InfoButton{}
}
