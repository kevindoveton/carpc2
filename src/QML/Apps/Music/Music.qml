import QtQuick 2.5
import QtQuick.Controls 2.1


Item {
    clip: true

    SwipeView {
        id: musicSwipeView
        currentIndex: 1
        anchors.fill: parent

        Item {
            id: musicPlaylist
            Rectangle {
                color: config.bgColor
                anchors.fill: parent
            }
        }
        Item {
            id: musicArtist
            Rectangle {
                color: config.bgColor
                anchors.fill: parent
                GridView {
                    cellWidth: parent.width /3
                    cellHeight: parent.height /3
                    anchors.fill: parent
                    model: music.artists
                    delegate: MusicArtistComponent { }
                    interactive: true
                }
            }


        }

        Item {
            id: musicAlbum
            Rectangle {
                color: config.bgColor
                anchors.fill: parent
                GridView {
                    cellWidth: parent.width /3
                    cellHeight: parent.height /3
                    anchors.fill: parent
                    model: music.albums
                    delegate: MusicAlbumComponent { }
                    interactive: true
                }
            }
        }

        Item {
            id: musicSong
            Rectangle {
                color: config.bgColor
                anchors.fill: parent
                ListView {
                    anchors.fill: parent
                    model: music.songs
                    delegate: MusicSongComponent { }
                    interactive: true
                }
            }
        }
    }

    PageIndicator {
        id: indicator

        count: musicSwipeView.count
        currentIndex: musicSwipeView.currentIndex

        anchors.bottom: musicSwipeView.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }


}

