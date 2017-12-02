import QtQuick 2.0

Item {
    Rectangle {
        anchors.fill: parent
        color: config.bgColor
    }


    Rectangle {
        width: 80
        height: parent.height
        x: parent.width - width - appSidebar.width
        color: config.bgColor
//        color: 'red'
        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            text: time.time
            color: 'white'
            font.capitalization: Font.AllUppercase
        }
    }

}
