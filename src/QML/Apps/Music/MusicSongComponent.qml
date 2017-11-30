import QtQuick 2.0

Component {
    id: musicArtistDelegate
    Item {
        width: parent.width
        height: 40
        Rectangle {
            anchors.centerIn: parent
            width: parent.width
            height: parent.height

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    music.currentSong = model.modelData.id;
                    player.songPath = model.modelData.path;
                }
            }

            Text {
                anchors.centerIn: parent
                width: parent.width
                horizontalAlignment: Text.AlignLeft
                text: model.modelData.name
            }
        }
    }
}
