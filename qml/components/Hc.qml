import QtQuick 2.15

Rectangle {
    id: root
    property string title: ""
    default property alias content: contentArea.data

    color: "#0A1E36"
    radius: 12
    border.color: "#1E4A6B"
    border.width: 1
    clip: true

    Rectangle {
        id: headerBar
        width: parent.width
        height: parent.height * 0.20
        radius: root.radius
        color: "#13406A"
        anchors.top: parent.top

        Rectangle {
            width: parent.width
            height: root.radius
            color: parent.color
            anchors.bottom: parent.bottom
        }

        Text {
            anchors.fill: parent
            anchors.leftMargin: parent.width * 0.04
            anchors.rightMargin: parent.width * 0.04
            text: root.title
            color: "#E6E6E6"
            font.bold: true
            font.family: "Consolas"
            font.pixelSize: parent.height * 0.45
            minimumPixelSize: 8
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
    }

    Item {
        id: contentArea
        anchors.top: headerBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: parent.width * 0.03
    }
}