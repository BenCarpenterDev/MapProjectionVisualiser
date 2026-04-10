import QtQuick 2.3
import QtTest 1.0
import "../../gui"

TestCase {
    name: "GUI_UT1_mapDisplay"
    when: windowShown

    MainView{id: mainWindow}

    function fileName(input){
        var fileString = input.split("/")
        return fileString[fileString.length - 1]
    }

    function test_displayVisible() {
        verify(mainWindow.visible)
        verify(mainWindow.worldMapContainer.visible)
        verify(!mainWindow.infoPanel.stateVisible)
        verify(mainWindow.infoButton.visible)
    }

    function test_defaultSource() {        
        compare(fileName(mainWindow.worldMap.source.toString()), "worldMap_webMercator.svg", "Default source should be world map in Web Mercator projection")
    }

    function test_defaultProjection() {        
        compare(mainWindow.projectionsPanel.projTwo.state, "Selected", "Web Mercator projection should be selected by default")
    }

    function test_defaultMap() {        
        compare(mainWindow.mapPanel.mapOne.state, "Selected", "World Map should be selected by default")
        verify(!mainWindow.mapPanel.gridEnabled, "Grid should be disabled by default")
    }
}