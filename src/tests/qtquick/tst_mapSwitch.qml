import QtQuick 2.3
import QtTest 1.0
import "../../gui"

TestCase {
    name: "Map Tests"
    when: windowShown

    MainView{id: mainWindow}

    function fileName(input){
        var fileString = input.split("/")
        return fileString[fileString.length - 1]
    }

    function test_GUI_IT12_mapWorldMap() {        
        mouseClick(mainWindow.mapPanel.mapOne)
        wait(100)
        compare(fileName(mainWindow.worldMap.source.toString()), "worldMap_webMercator.svg", "Selected map should be world map")
    }

    function test_GUI_IT13_mapPangea() {        
        mouseClick(mainWindow.mapPanel.mapTwo)
        wait(100)
        compare(fileName(mainWindow.worldMap.source.toString()), "preHistoricMap_webMercator.svg", "Selected map should be Pangea map")
    }

    function test_GUI_IT14_mapShapes() {        
        mouseClick(mainWindow.mapPanel.mapThree)
        wait(100)
        compare(fileName(mainWindow.worldMap.source.toString()), "shapesMap_webMercator.svg", "Selected map should be shapes map")
    }

    function test_GUI_IT15_mapMars() {        
        mouseClick(mainWindow.mapPanel.mapFour)
        wait(100)
        compare(fileName(mainWindow.worldMap.source.toString()), "marsMap_webMercator.svg", "Selected map should be Mars map")
    }

    function test_GUI_IT16_mapGrid() {        
        mouseClick(mainWindow.mapPanel.gridToggle)
        wait(100)
        verify(mainWindow.mapPanel.gridEnabled, "Grid should be enabled")
        mouseClick(mainWindow.mapPanel.gridToggle)
        wait(100)
        verify(!mainWindow.mapPanel.gridEnabled, "Grid should be disabled")
    }

}