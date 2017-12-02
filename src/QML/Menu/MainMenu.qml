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
//            Rectangle {
//                color: 'green'
//                width: parent.width
//                height: parent.height
//            }

            Rectangle {
                anchors.centerIn: parent
                width: 140
                height: 130
                color: 'transparent'
//                color: config.bgColor
//                color: 'red'
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

                Rectangle {
                    x: parent.width * 0.15
                    y: 105
                    color: 'white'
                    opacity: 0.2
                    height: 1
                    width: parent.width * 0.7
                }


                Text {
                    y: 110
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                    text: name
                    color: 'white'
                    font.capitalization: Font.AllUppercase
                }
            }
        }
    }

    GridView {
        x: 0
        y: parent.height * 0.15
        width: parent.width
        height: parent.height * 0.7

        cellWidth: parent.width /3
        cellHeight: height / 2
        model: menuModel
        delegate: menuDelegate
        interactive: false
    }
}
