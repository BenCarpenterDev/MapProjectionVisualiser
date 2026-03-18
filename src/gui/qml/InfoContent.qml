import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item{
    id: infoContent
    width: parent.width
    property string panelTitle
    property string panelInfo
    property string panelUseCases
        
    Column{
    spacing: 10
    padding: 20
        Text{
            text: panelTitle
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            font.family: "Helvetica"
            font.pointSize: 20
            font.bold: true
            color: "#f4f0ec"
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: panelInfo
            font.family: "Helvetica"
            font.pointSize: 12
            color: "#f4f0ec"
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: "Use Cases"
            font.family: "Helvetica"
            font.pointSize: 18
            font.bold: true
            color: "#b9f2ff"
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: panelUseCases
            font.family: "Helvetica"
            font.pointSize: 12
            color: "#b9f2ff"
        }
    }
    

    states: [
        State {
            name: "wgs84"
            when: (infoPanel.contentProjection === "wgs84")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "WGS84 / World Geodetic System"; 
                panelInfo: "Woo"
                panelUseCases: "The standard for cartography, geodesy, and navigation, including GPS."
            }
        },
        State {
            name: "webMercator"
            when: (infoPanel.contentProjection === "webMercator")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "Web Mercator"; 
                panelInfo: "The mainstream standard map projection used throughout various media." 
                panelUseCases: "Used by most online mapping platforms, such as Google Maps and OpenStreetMap."
            }
        },
        State {
            name: "gallStereographic"
            when: (infoPanel.contentProjection === "gallStereographic")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "Gall Stereographic"; 
                panelInfo: "needs writing" 
                panelUseCases: "needs writing"
            }
        },
        State {
            name: "winkelTripel"
            when: (infoPanel.contentProjection === "winkelTripel")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "Winkel Tripel"; 
                panelInfo: "needs writing" 
                panelUseCases: "needs writing"
            }
        },
        State {
            name: "gallPeters"
            when: (infoPanel.contentProjection === "gallPeters")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "Gall Peters"; 
                panelInfo: "needs writing" 
                panelUseCases: "needs writing"
            }
        },
        State {
            name: "sinusoidal"
            when: (infoPanel.contentProjection === "sinusoidal")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "Sinusoidal"; 
                panelInfo: "needs writing" 
                panelUseCases: "needs writing"
            }
        }
    ]
}