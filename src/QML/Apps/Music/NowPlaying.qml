import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    property var album: music.nowPlayingAlbum
    property var artist: music.nowPlayingArtist
    property var song: music.nowPlayingSong

    Rectangle {
        color: config.bgColor
        anchors.fill: parent

        Image {
            id: nowPlaying_albumImage
            x: parent.width * 0.1
            y: parent.height * 0.25
            height: parent.height * 0.5
            width: height
            source: album.image
            fillMode: Image.PreserveAspectCrop
            clip: true
            property bool rounded: true
            property bool adapt: true

            layer.enabled: rounded
            layer.effect: OpacityMask {
                maskSource: Item {
                    width: nowPlaying_albumImage.width
                    height: nowPlaying_albumImage.height
                    Rectangle {
                        anchors.centerIn: parent
                        width: nowPlaying_albumImage.adapt ? nowPlaying_albumImage.width : Math.min(nowPlaying_albumImage.width, nowPlaying_albumImage.height)
                        height: nowPlaying_albumImage.adapt ? nowPlaying_albumImage.height : width
                        radius: 5
                    }
                }
            }
        }

        Text {
            y: 100
            anchors.left: nowPlaying_albumImage.right
            anchors.leftMargin: 30
            color: 'white'
            text: artist.name
        }

        Text {
            y: 200
            anchors.left: nowPlaying_albumImage.right
            anchors.leftMargin: 30
            color: 'white'
            font.capitalization: Font.AllUppercase
            font.pixelSize: 20
            text: song.name
        }

        Text {
            y: 300
            anchors.left: nowPlaying_albumImage.right
            anchors.leftMargin: 30
            id: nowPlaying_albumText
            color: 'white'
            text: album.name
        }

        MusicControlBar {
            width: parent.width
            anchors.bottom: parent.bottom
        }
    }
}
