import QtQuick 2.0

Component {
    id: musicArtistDelegate
    Item {
        width: GridView.view.cellWidth
        height: GridView.view.cellHeight
        Rectangle {
            anchors.centerIn: parent
            width: 120
            height: 120

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    music.currentAlbum = model.modelData.id;
                    musicSwipeView.currentIndex = 3;
                }
            }

            Item {
                width: 120
                height: 100
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                Image {
                    id: myIcon
                    anchors.fill: parent
                    source: model.modelData.image
                    fillMode: Image.PreserveAspectCrop
                    clip: true
                }
            }

            Text {
                anchors.bottom: parent.bottom
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                text: model.modelData.name
            }
        }
    }
}
