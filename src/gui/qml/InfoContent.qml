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
            width: infoContent.width * 0.9
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
                panelTitle: "WGS84"; 
                panelInfo: 
"This is the World Geodetic System, a standard used for mapping and navigation. This system provids a solution to defining locations on Earth, refered to as a reference system.
\nWGS84 is the latest version, created in 1984 and updated in 2004. 
\nThis system is maintained by the United States National Geospatial-Intelligence Agency"

                panelUseCases: "Widely used in GPS technology. 
\nThe raw format for the map you're currently looking at, GeoJSON, uses WGS84 with longitude and latitude degree units."
            }
        },
        State {
            name: "webMercator"
            when: (infoPanel.contentProjection === "webMercator")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "Mercator"; 
                panelInfo: "The mainstream standard map projection used throughout various literature and online services, created by Geradus Mercator in 1569.
\nThis is a conformal cylindirical projection, meaning it preserves angles and shapes locally, but distorts areas, especially near the poles. Size of lands are inflated the further they are from the equator.
\nWeb Mercator is a variant of the original Mercator projection, it's the standard for web mapping applications. Formulas are the same as the standard variation." 
                panelUseCases: "Used by most online mapping platforms, such as Google Maps and OpenStreetMap."
            }
        },
        State {
            name: "gallStereographic"
            when: (infoPanel.contentProjection === "gallStereographic")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "Gall Stereographic"; 
                panelInfo: "A cylindrical projection created by James Gall in 1855. This projection attempts to balance distortion, it distorts sizes less than Mercator and distorts shapes less than Equirectangular." 
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
        },
        State {
            name: "equalEarth"
            when: (infoPanel.contentProjection === "equalEarth")
            PropertyChanges { 
                target: infoContent; 
                panelTitle: "Equal Earth"; 
                panelInfo: "needs writing" 
                panelUseCases: "needs writing"
            }
        }
    ]
}