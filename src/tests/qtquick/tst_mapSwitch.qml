import QtQuick 2.3
import QtTest 1.0
import "../../gui"

TestCase {
    name: "GUI_IT5_mapSwitch"
    when: windowShown

    MainView{id: mainWindow}

    function fileName(input){
        var fileString = input.split("/")
        return fileString[fileString.length - 1]
    }

    function test_worldMapSwitch() {        
        mouseClick(mainWindow.mapPanel.mapOne)
        wait(100)
        compare(fileName(mainWindow.worldMap.source.toString()), "worldMap_webMercator.svg", "Selected map should be world map")
    }

    function test_pangeaSwitch() {        
        mouseClick(mainWindow.mapPanel.mapTwo)
        wait(100)
        compare(fileName(mainWindow.worldMap.source.toString()), "preHistoricMap_webMercator.svg", "Selected map should be Pangea map")
    }

    function test_shapesSwitch() {        
        mouseClick(mainWindow.mapPanel.mapThree)
        wait(100)
        compare(fileName(mainWindow.worldMap.source.toString()), "shapesMap_webMercator.svg", "Selected map should be shapes map")
    }

    function test_marsSwitch() {        
        mouseClick(mainWindow.mapPanel.mapFour)
        wait(100)
        compare(fileName(mainWindow.worldMap.source.toString()), "marsMap_webMercator.svg", "Selected map should be Mars map")
    }

}