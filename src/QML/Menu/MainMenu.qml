import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Rectangle {
    ListModel {
        id: menuModel

        ListElement {
            name: "Music"
            icon: "qrc:/icons/music.png"
            link: "../Apps/Music/Music.qml"
        }
        ListElement {
            name: "Maps"
            icon: "qrc:/icons/maps.png"
            link: "../Apps/Maps/Maps.qml"
        }
        ListElement {
            name: "Contacts"
            icon: "qrc:/icons/contacts.png"
            link: "../Apps/Contacts/Contacts.qml"
        }
        ListElement {
            name: "Messages"
            icon: "qrc:/icons/messages.png"
            link: "../Apps/Messages/Messaages.qml"
        }
        ListElement {
            name: "Phone"
            icon: "qrc:/icons/phone.png"
            link: "../Apps/Phone/Phone.qml"
        }
        ListElement {
            name: "Airplay"
            icon: "qrc:/icons/music.png"
            link: "../Apps/Airplay/Airplay.qml"
        }
    }

    Component {
        id: menuDelegate
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
                        appStack.push(Qt.resolvedUrl(link))
                    }
                }

                Item {
                    width: 100
                    height: 100
                    anchors.horizontalCenter: parent.horizontalCenter
                    Image {
                        id: myIcon
                        anchors.fill: parent
                        source: icon
                    }
                }

                Text {
                    y: 110
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                    text: name
                }
            }
        }
    }

    GridView {
        cellWidth: parent.width /3
        cellHeight: parent.height /3
        anchors.fill: parent
        model: menuModel
        delegate: menuDelegate
        interactive: false
    }
}
