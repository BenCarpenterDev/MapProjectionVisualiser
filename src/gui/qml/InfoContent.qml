import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item{
    id: infoContent
    width: parent.width
    property string panelTitle
    property string projectionCreator
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

        Text{
            text: projectionCreator
            width: infoContent.width * 0.9
            wrapMode: Text.WordWrap
            font.family: "Helvetica"
            font.pointSize: 8
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
            text: "Usage"
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
                target: infoContent 
                panelTitle: "WGS84"
                projectionCreator: "Maintained by United States National Geospatial-Intelligence Agency in 1984, updated in 2004"
                panelInfo: 
"This is the World Geodetic System, a standard used for mapping and navigation. This system provids a solution to defining locations on Earth, refered to as a reference system.
\nWGS84 is the latest version, created in 1984 and updated in 2004."

                panelUseCases: "Widely used in GPS technology. 
\nThe raw format for the map you're currently looking at, GeoJSON, uses WGS84 with longitude and latitude degree units."
            }
        },
        State {
            name: "webMercator"
            when: (infoPanel.contentProjection === "webMercator")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Mercator"
                projectionCreator: "Created by Geradus Mercator in 1569"
                panelInfo: "The mainstream standard map projection used throughout various literature and online services.
\nThis is a conformal cylindirical projection, meaning it preserves angles and shapes locally, but distorts areas, especially near the poles. Size of lands are inflated the further they are from the equator.
\nWeb Mercator is a variant of the original Mercator projection, it's the standard for web mapping applications. Formulas are the same as the standard variation." 
                panelUseCases: "Used by most online mapping platforms, such as Google Maps and OpenStreetMap."
            }
        },
        State {
            name: "gallStereographic"
            when: (infoPanel.contentProjection === "gallStereographic")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Gall Stereographic"
                projectionCreator: "Created by James Gall in 1855"
                panelInfo: "This cylindrical projection which distorts sizes less than Mercator and distorts shapes less than Equirectangular." 
                panelUseCases: "Used in several British and United States atlases."
            }
        },
        State {
            name: "winkelTripel"
            when: (infoPanel.contentProjection === "winkelTripel")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Winkel Tripel"
                projectionCreator: "Created by Oswald Winkel in 1921"
                panelInfo: "A modified azimuhtal projection aiming to minimise three ('tripel') kinds of distortions; area, direction and distance." 
                panelUseCases: "Used as the standard by the National Geographic Society since 1998, replacing the Robinson Projection.
\nAlso used widely by educational institudes and textbooks."
            }
        },
        State {
            name: "gallPeters"
            when: (infoPanel.contentProjection === "gallPeters")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Gall Peters"
                projectionCreator: "Created by James Gall in 1855 and reintroduced by Arno Peters in 1973"
                panelInfo: "A rectangular equal-area projection." 
                panelUseCases: "Widely used by British Schools.
\nAdditionally, Massachusetts and Boston public schools utilise this projection as standard since March 2017."
            }
        },
        State {
            name: "sinusoidal"
            when: (infoPanel.contentProjection === "sinusoidal")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Sinusoidal"
                projectionCreator: "Created by Jean Cossin in 1570"
                panelInfo: "A pseuodcylindrical equal-area projection which represents the poles as points with distorted meridans and continents.
\nThe equator and central meridians are the most accurate, distortion occuring the further away from the centre, increasing inaccuracies." 
                panelUseCases: "Used by NASA's Moderate Resolution Imaging Spectroradimater team."
            }
        },
        State {
            name: "equalEarth"
            when: (infoPanel.contentProjection === "equalEarth")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Equal Earth"
                projectionCreator: "Created by Bojan Šavrič, Bernhard Jenny and Tom Patterson in 2018"
                panelInfo: "A modern equal-area pseudocylindrical projection aiming to retain the sizes of areas." 
                panelUseCases: "Was used by NASA's Goddard Institude for Space Studies showing the global mean temperature anamoly.
\n'Correct the Map' campaign has declared the wider adoption for this projection as an alternative to Mercator."
            }
        }
    ]
}