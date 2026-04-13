import QtQuick 2.3
import QtTest 1.0
import "../../gui"

TestCase {
    name: "Information Panel Tests"
    when: windowShown

    MainView{id: mainWindow}

    function test_GUI_IT17_informationPanelToggle() {        
        mouseClick(mainWindow.infoButton)
        wait(100)
        verify(mainWindow.infoPanel.stateVisible, "Panel should be enabled")
        mouseClick(mainWindow.infoButton)
        wait(100)
        verify(!mainWindow.infoPanel.stateVisible, "Panel should be disabled")
    }

    function test_GUI_IT18_informationWGS84() {        
        mouseClick(mainWindow.projectionsPanel.projOne)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "wgs84", "Selected projection should be WGS84")
    }

    function test_GUI_IT19_informationWebMercator() {        
        mouseClick(mainWindow.projectionsPanel.projTwo)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "webMercator", "Selected projection should be Web Mercator")
    }

    function test_GUI_IT20_informationGallStereographic() {        
        mouseClick(mainWindow.projectionsPanel.projThree)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "gallStereographic", "Selected projection should be Gall Stereographic")
    }

    function test_GUI_IT21_informationWinkelTripel() {        
        mouseClick(mainWindow.projectionsPanel.projFour)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "winkelTripel", "Selected projection should be Winkel Tripel")
    }

    function test_GUI_IT22_informationGallPeters() {        
        mouseClick(mainWindow.projectionsPanel.projFive)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "gallPeters", "Selected projection should be Gall Peters")
    }

    function test_GUI_IT23_informationSinusoidal() {        
        mouseClick(mainWindow.projectionsPanel.projSix)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "sinusoidal", "Selected projection should be Sinusoidal")
    }

    function test_GUI_IT24_informationEqualEarth() {        
        mouseClick(mainWindow.projectionsPanel.projSeven)
        wait(100)
        compare(mainWindow.infoPanel.contentProjection, "equalEarth", "Selected projection should be Equal Earth")
    }

}