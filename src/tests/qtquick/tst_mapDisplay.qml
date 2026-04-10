import QtQuick 2.3
import QtTest 1.0
import "../../gui"

TestCase {
    name: "GUI_UT1_mapDisplay"
    when: windowShown

    MainView{id: mainWindow}

    function test_displayVisible() {
        verify(mainWindow.visible)
        verify(mainWindow.worldMapContainer.visible)
    }


}