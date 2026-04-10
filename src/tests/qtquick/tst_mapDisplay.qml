import QtQuick 2.3
import QtTest 1.0

TestCase {
    name: "GUI_UT1_mapDisplay"
    when: windowShown

    function test_displayVisible() {
        verify(mainWindow.visible, "mapDisplay should be visible")
    }

}