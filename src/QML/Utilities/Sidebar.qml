import QtQuick 2.7
import QtQuick.Layouts 1.3
import com.kdoveton.carpc.SystemVolume 1.0
Item {
    width: 50
    height: parent.height

    VerticalLine {
        height: parent.height
        width: 1
        color: "blue"
    }

    SystemVolume {
        id: systemVolume
    }

    ColumnLayout {
        spacing: 50
        anchors.centerIn: parent

        Rectangle {
            id: sidebarShortcut
            height: 50
            width: 50
            radius: 5
            color: "#333333"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    systemVolume.decreaseVolume();
                    console.warn(systemVolume.decreaseVolume());
                }
            }
        }

        Rectangle {
            id: sidebarHome
            height: 50
            width: 50
            radius: 5
            color: "#00b000"
            MouseArea {
                anchors.fill: parent
                onClicked: appStack.clear()
            }
        }

        Rectangle {
            id: sidebarBack
            height: 50
            width: 50
            radius: 5
            color: "#0000b0"
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
