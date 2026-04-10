import QtQuick 2.3
import QtTest 1.0
import "../../gui"

TestCase {
    name: "GUI_IT4_informationPanel"
    when: windowShown

    MainView{id: mainWindow}

    function test_panelToggle() {        
        mouseClick(mainWindow.infoButton)
        wait(100)
        verify(mainWindow.infoPanel.stateVisible, "Panel should be enabled")
        mouseClick(mainWindow.infoButton)
        wait(100)
        verify(!mainWindow.infoPanel.stateVisible, "Panel should be disabled")
    }

    function test_wgs84Content() {        
        mouseClick(mainWindow.projectionsPanel.projOne)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "wgs84", "Selected projection should be WGS84")
    }

    function test_webMercatorContent() {        
        mouseClick(mainWindow.projectionsPanel.projTwo)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "webMercator", "Selected projection should be Web Mercator")
    }

    function test_gallStereographicContent() {        
        mouseClick(mainWindow.projectionsPanel.projThree)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "gallStereographic", "Selected projection should be Gall Stereographic")
    }

    function test_winkelTripelContent() {        
        mouseClick(mainWindow.projectionsPanel.projFour)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "winkelTripel", "Selected projection should be Winkel Tripel")
    }

    function test_gallPetersContent() {        
        mouseClick(mainWindow.projectionsPanel.projFive)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "gallPeters", "Selected projection should be Gall Peters")
    }

    function test_sinusoidalContent() {        
        mouseClick(mainWindow.projectionsPanel.projSix)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "sinusoidal", "Selected projection should be Sinusoidal")
    }

    function test_equalEarthContent() {        
        mouseClick(mainWindow.projectionsPanel.projSeven)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "equalEarth", "Selected projection should be Equal Earth")
    }

}