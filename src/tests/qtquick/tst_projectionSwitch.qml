import QtQuick 2.3
import QtTest 1.0
import "../../gui"

TestCase {
    name: "GUI_IT4_projectionSwitch"
    when: windowShown

    MainView{id: mainWindow}

    function projectionName(input){
        var fileString = input.split("/")
        var nameString = fileString[fileString.length - 1].split("_")
        return nameString[nameString.length - 1]
    }

    function test_wgs84() {        
        mouseClick(mainWindow.projectionsPanel.projOne)
        wait(100)
        compare(projectionName(mainWindow.worldMap.source.toString()), "wgs84.svg", "Selected projection should be WGS84")
    }

    function test_webMercator() {        
        mouseClick(mainWindow.projectionsPanel.projTwo)
        wait(100)
        compare(projectionName(mainWindow.worldMap.source.toString()), "webMercator.svg", "Selected projection should be Web Mercator")
    }

    function test_gallStereographic() {        
        mouseClick(mainWindow.projectionsPanel.projThree)
        wait(100)
        compare(projectionName(mainWindow.worldMap.source.toString()), "gallStereographic.svg", "Selected projection should be Gall Stereographic")
    }

    function test_winkelTripel() {        
        mouseClick(mainWindow.projectionsPanel.projFour)
        wait(100)
        compare(projectionName(mainWindow.worldMap.source.toString()), "winkelTripel.svg", "Selected projection should be Winkel Tripel")
    }

    function test_gallPeters() {        
        mouseClick(mainWindow.projectionsPanel.projFive)
        wait(100)
        compare(projectionName(mainWindow.worldMap.source.toString()), "gallPeters.svg", "Selected projection should be Gall Peters")
    }

    function test_sinusoidal() {        
        mouseClick(mainWindow.projectionsPanel.projSix)
        wait(100)
        compare(projectionName(mainWindow.worldMap.source.toString()), "sinusoidal.svg", "Selected projection should be Sinusoidal")
    }

    function test_equalEarth() {        
        mouseClick(mainWindow.projectionsPanel.projSeven)
        wait(100)
        compare(projectionName(mainWindow.worldMap.source.toString()), "equalEarth.svg", "Selected projection should be Equal Earth")
    }

}