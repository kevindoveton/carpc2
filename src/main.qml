import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: qsTr("CarPC")

    Header {
        id: appHeader
        height: 30
        width: parent.width - appSidebar.width
    }

    MainMenu {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: parent.width - appSidebar.width
        height: parent.height - appHeader.height
    }

    StackView {
        id: appStack
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: parent.width - appSidebar.width
        height: parent.height - appHeader.height
    }

    Sidebar {
        id: appSidebar
        anchors.right: parent.right
        anchors.top: Header.bottom
    }


}
