import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    id: infoContent
    width: parent.width
    property string panelTitle
    property string panelInfo

    Text{
        id: infoTitle
        text: panelTitle
        wrapMode: Text.WordWrap
        font.family: "Helvetica"
        font.pointSize: 20
        color: "white"
    }

    Text {
        id: infoText
        width: 10
        wrapMode: Text.Wrap
        text: panelInfo
        font.family: "Helvetica"
        font.pointSize: 14
        color: "white"
    }
    states: [
        State {
            name: "wgs84"
            when: (infoPanel.contentProjection === "wgs84")
            PropertyChanges { target: infoContent; panelTitle: "WGS84 / World Geodetic System"; panelInfo: "Woo" }
        },
        State {
            name: "webMercator"
            when: (infoPanel.contentProjection === "webMercator")
            PropertyChanges { 
            target: infoContent; 
            panelTitle: "Mercator Projection"; 
            panelInfo: "The mainstream standard map projection used throughout various media." }
        }
    ]
}