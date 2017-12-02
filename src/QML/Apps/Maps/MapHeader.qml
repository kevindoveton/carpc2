import QtQuick 2.0
import QtQuick.VirtualKeyboard 2.1

Rectangle {
    anchors.fill: parent
    color: 'transparent'
    Rectangle {
        width: parent.width
        height: parent.height
        opacity: 0.7
        color: '#333333'
    }

    Rectangle {
        anchors.centerIn: parent
        width: parent.width * 0.75
        height: 100
        opacity: 1

        TextInput {
            width: parent.width * 0.8
            height: parent.height * 0.8
            anchors.centerIn: parent
            font.pixelSize: 32
            verticalAlignment: TextInput.AlignVCenter
            Text {
                text: config.mapPlaceholderSearchText
                color: '#999999'
                visible: !parent.text
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 32
            }
        }
    }

}
