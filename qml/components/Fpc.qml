import QtQuick 2.15

HMICard {
    title: "PROGRESS"

    Item {
        anchors.fill: parent

        Text {
            id: totalLabel
            text: "TOTAL:"
            color: "#C8D6E5"
            font.pixelSize: parent.height * 0.13
            font.bold: false
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: parent.height * 0.08
            anchors.leftMargin: parent.width * 0.06
        }

        Text {
            id: bigValue
            text: fuelModel.currentVolume.toFixed(2)
            color: "#E6E6E6"
            font.bold: true
            
            font.pixelSize: Math.min(parent.width * 0.38, parent.height * 0.52)
            font.family: "Consolas"
            font.letterSpacing: 2
            anchors.centerIn: parent
            anchors.verticalCenterOffset: parent.height * 0.08
            
            minimumPixelSize: 12
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            width: parent.width * 0.88
            height: parent.height * 0.65
        }
    }
}