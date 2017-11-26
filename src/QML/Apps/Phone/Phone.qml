import QtQuick 2.0

Rectangle {
    color: 'red'
    anchors.fill: parent
    MouseArea {
        anchors.fill: parent
        onClicked: console.log(parent.width)
    }
}

