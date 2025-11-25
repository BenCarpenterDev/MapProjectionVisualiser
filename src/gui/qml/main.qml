import QtQuick
import QtQuick.Shapes
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.VectorImage

Window {
    id: mainWindow

    title: qsTr("Europe Test")
    width: 1920
    height: 1080
    visible: true
    visibility: Window.Maximized
    color: "white"

    Rectangle {
        id: bgFill
        color: "#9FCBF9"
        anchors.fill: parent
    
        VectorImage {
                scale: 1.5
                width: mainWindow.sourceSize
                height: mainWindow.sourceSize
                preferredRendererType: VectorImage.CurveRenderer
                source: "qrc:/src/resources/Europe.svg"
                anchors.centerIn: parent
            }
    }
}
