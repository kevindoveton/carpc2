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
                color: 'red'
                anchors.fill: parent
            }
        }
        Item {
            id: musicArtist
            Rectangle {
                color: 'blue'
                anchors.fill: parent
            }
        }

        Item {
            id: musicAlbum
            Rectangle {
                color: 'blue'
                anchors.fill: parent
            }
        }

        Item {
            id: musicSong
            Rectangle {
                color: 'blue'
                anchors.fill: parent
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

