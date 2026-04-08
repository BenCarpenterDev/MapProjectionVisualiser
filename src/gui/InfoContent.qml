import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item{
    id: infoContent
    width: parent.width
    property string panelTitle
    property string projectionCreator
    property string panelInfo
    property string panelPros
    property string panelLimitations
    property string panelUseCases

    property int textSize: 12
    property bool prosAndConsVisible: true
        
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
            style: Text.Raised; 
            styleColor: "gray"
        }

        Text{
            text: projectionCreator
            width: infoContent.width * 0.9
            wrapMode: Text.WordWrap
            font.family: "Helvetica"
            font.pointSize: 8
            font.bold: true
            color: "#f4f0ec"
            style: Text.Raised; 
            styleColor: "gray"
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: panelInfo
            font.family: "Helvetica"
            font.pointSize: textSize
            color: "#f4f0ec"
            style: Text.Raised; 
            styleColor: "gray"
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: "Strengths"
            font.family: "Helvetica"
            font.pointSize: textSize
            font.bold: true
            color: "#85D945"
            style: Text.Raised; 
            styleColor: "gray"
            visible: prosAndConsVisible
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: panelPros
            font.family: "Helvetica"
            font.pointSize: textSize
            color: "#85D945"
            style: Text.Raised; 
            styleColor: "gray"
            visible: prosAndConsVisible
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: "Limitations"
            font.family: "Helvetica"
            font.pointSize: textSize
            font.bold: true
            color: "#F0372D"
            style: Text.Raised; 
            styleColor: "gray"
            visible: prosAndConsVisible
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: panelLimitations
            font.family: "Helvetica"
            font.pointSize: textSize
            color: "#F0372D"
            style: Text.Raised; 
            styleColor: "gray"
            visible: prosAndConsVisible
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: "Usage"
            font.family: "Helvetica"
            font.pointSize: textSize
            font.bold: true
            color: "#b9f2ff"
            style: Text.Raised; 
            styleColor: "gray"
        }

        Text {
            width: infoContent.width * 0.8
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text: panelUseCases
            font.family: "Helvetica"
            font.pointSize: textSize
            color: "#b9f2ff"
            style: Text.Raised; 
            styleColor: "gray"
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
                panelInfo: "This is not a projection, this is a geodetic reference system. This shows the map before a projection is applied.
\nThis is the World Geodetic System, a standard used for mapping and navigation. This system provids a solution to defining locations on Earth, refered to as a reference system.
\nWGS84 is the latest version, created in 1984 and updated in 2004."
                panelUseCases: "Widely used in GPS technology. 
\nThe raw format for the map you're currently looking at, GeoJSON, uses WGS84 with longitude and latitude degree units."
                prosAndConsVisible: false
            }
        },
        State {
            name: "webMercator"
            when: (infoPanel.contentProjection === "webMercator")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Mercator"
                projectionCreator: "Created by Geradus Mercator in 1569"
                panelInfo: "The mainstream standard map projection used throughout various literature and online services. Web Mercator is a variant of the original Mercator projection, it's the standard for web mapping applications. Formulas are the same as the standard variation." 
                panelPros: "Preserves angles and shapes locally, useful for navigation and online mapping applications."
                panelLimitations: "Distorts areas, especially near the poles. Size of lands are inflated the further they are from the equator."
                panelUseCases: "Used by most online mapping platforms, such as Google Maps and OpenStreetMap."
                prosAndConsVisible: true
            }
        },
        State {
            name: "gallStereographic"
            when: (infoPanel.contentProjection === "gallStereographic")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Gall Stereographic"
                projectionCreator: "Created by James Gall in 1855"
                panelInfo: "A cylindrical map projection with two standard parallels at latitudes 45° north and south." 
                panelPros: "Distortion is more balanced than other projections such as Mercator. The projection is correctly scaled and no distortion along the standard parallels at 45° north and south"
                panelLimitations: "Distortion increases away from the standard parallels, and it is extreme at the polar regions"
                panelUseCases: "Used in several British and United States atlases."
                prosAndConsVisible: true
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
                panelPros: "Graticule grid is symmetric across the equator and the central meridian."
                panelLimitations: "Polar regions are exaggerated, this projection also has low mean scale and area distortion."
                panelUseCases: "Used as the standard by the National Geographic Society since 1998, replacing the Robinson Projection.
\nAlso used widely by educational institudes and textbooks."
                prosAndConsVisible: true
            }
        },
        State {
            name: "gallPeters"
            when: (infoPanel.contentProjection === "gallPeters")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Gall Peters"
                projectionCreator: "Created by James Gall in 1855 and reintroduced by Arno Peters in 1973"
                panelInfo: "A rectangular equal-area projection.
\nAdditionally, Massachusetts and Boston public schools utilise this projection as standard since March 2017."
                panelUseCases: "Widely used by British Schools."
                panelPros: "Retains the relative size of areas."
                panelLimitations: "Greatly distrorts tropical and polar regions. Not appropriate for small-scale mapping."
                prosAndConsVisible: true
            }
        },
        State {
            name: "sinusoidal"
            when: (infoPanel.contentProjection === "sinusoidal")
            PropertyChanges { 
                target: infoContent
                panelTitle: "Sinusoidal"
                projectionCreator: "Created by Jean Cossin in 1570"
                panelInfo: "A pseuodcylindrical equal-area projection which represents the poles as points with distorted meridans and continents."
                panelPros: "The equator and central meridians are the most accurate"
                panelLimitations: "Distortion occursthe further away from the centre, increasing inaccuracies. Poles are shown as points."
                panelUseCases: "Used by NASA's Moderate Resolution Imaging Spectroradimater team."
                prosAndConsVisible: true
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
                panelPros: "Retains the relative size of areas while remaining visually pleasing."
                panelLimitations: "Still some distortion in the tropical and polar regions."
                panelUseCases: "Was used by NASA's Goddard Institude for Space Studies showing the global mean temperature anamoly.
\n'Correct the Map' campaign has declared the wider adoption for this projection as an alternative to Mercator."
                prosAndConsVisible: true
            }
        }
    ]
}