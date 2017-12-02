import QtQuick 2.7
import QtQuick.Layouts 1.3

Item {
    width: 50
    height: parent.height

    Rectangle {
        height: parent.height
        width: parent.width
        color: config.bgColor
    }

    VerticalLine {
        height: parent.height * 0.8
        width: 1
        color: 'white'
        opacity: .15
        x: 0
        y: parent.height * 0.1
    }

    ColumnLayout {
        spacing: 50
        anchors.centerIn: parent

        Item {
            height: 50
            width: 50

            Rectangle {
                id: sidebarShortcut
                x: parent.width * 0.25
                y: parent.width * 0.25
                width: parent.width * 0.5
                height: width
                radius: 5
                color: "#333333"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    appStack.push("../Apps/Music/NowPlaying.qml")
                }
            }
        }

        Item {
            height: 50
            width: 50

            Rectangle {
                id: sidebarHome
                x: parent.width * 0.25
                y: parent.width * 0.25
                width: parent.width * 0.5
                height: width
                radius: 3
                color: "transparent"
                border.width: 2
                border.color: 'white'
            }

            MouseArea {
                anchors.fill: parent
                onClicked: appStack.clear()
            }
        }


        Item {
            height: 50
            width: 50

            Rectangle {
                id: sidebarBack
                x: parent.width * 0.25
                y: parent.width * 0.25
                width: parent.width * 0.5
                height: width
                radius: 5
                color: "#999999"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (appStack.depth > 1) {
                        appStack.pop();
                    } else {
                        appStack.clear();
                    }
                }
            }
        }

    }

}
