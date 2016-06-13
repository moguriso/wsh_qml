import QtQuick 2.5

Rectangle {
    property alias _artwork: _artwork
    property alias mouseArea1: mouseArea1

    Artwork{
        id: _artwork
    }

    Column {
        id: title_colum
        height: 62
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        Rectangle {
            id: title
            color: "#ccffffff"
            anchors.fill: parent
        }
    }

    MouseArea {
        id: mouseArea1
        x: 0
        y: 0
        width: 640
        height: 62
    }
}
