import QtQuick 2.15

Rectangle {
    id: root
    property string label: "FUEL"
    property string subLabel: ""
    property string iconSource: ""
    property bool isSelected: false
    property bool isSimPressed: false 
    property color glowColor: "#FFFFFF" 
    property color borderColor: (isSelected || isSimPressed) ? glowColor : "#2A4D69"

    radius: 8
    color: "#0B1A2A" 
    border.width: (isSelected || isSimPressed) ? 3 : 1
    border.color: borderColor

    Rectangle {
        anchors.fill: parent
        radius: parent.radius
        
        opacity: (root.isSelected || root.isSimPressed) ? 0.4 : 0.0
        
        gradient: Gradient {
            GradientStop { position: 0.0; color: root.glowColor }
            GradientStop { position: 1.0; color: "transparent" }
        }
        
        Behavior on opacity { NumberAnimation { duration: 150 } }
    }

    Image {
        id: dropIcon
        source: root.iconSource
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.15
        width: parent.width * 0.5
        height: width
        fillMode: Image.PreserveAspectFit
    }

    Column {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.1
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 2

        Text {
            text: root.subLabel
            color: (root.isSelected || root.isSimPressed) ? root.glowColor : "white"
            font.bold: true
            font.pixelSize: Math.min(root.width, root.height) * 0.2
            anchors.horizontalCenter: parent.horizontalCenter
            visible: text !== ""
        }
        Text {
            text: root.label
            color: "white"
            font.bold: true
            font.pixelSize: Math.min(root.width, root.height) * 0.15
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}