import QtQuick 2.0

Rectangle {
    height: 75
    width: parent.width
    color: '#333333'
    opacity: 0.75

    Rectangle {
        x: 0
        y: 0
        width: parent.width
        height: 1
        color: 'white'
        opacity: 1
    }

    Rectangle {
        width: 50
        height: width
        color: player.playing ? 'red' : 'blue'
        MouseArea {
            anchors.fill: parent
            onClicked: player.playPause();
        }
    }

}
