import QtQuick 2.15

HMICard {
    title: "METER"

    Item {
        anchors.fill: parent
        anchors.margins: parent.width * 0.04

        Column {
            anchors.fill: parent
            spacing: 0

            Item {
                width: parent.width
                height: parent.height * 0.32
                Text {
                    text: "TOTAL FUEL:"
                    color: "#A8B8CC"
                    font.pixelSize: parent.height * 0.18
                    anchors.top: parent.top
                    anchors.left: parent.left
                }
                Text {
                    text: fuelModel.currentVolume.toFixed(2) + " L"
                    color: "#E6E6E6"
                    font.bold: true
                    font.family: "Consolas"
                    font.pixelSize: Math.min(parent.width * 0.32, parent.height * 0.55)
                    fontSizeMode: Text.Fit
                    minimumPixelSize: 10
                    anchors.centerIn: parent
                    anchors.verticalCenterOffset: parent.height * 0.12
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Rectangle { width: parent.width; height: 1; color: "#2A4D69"; opacity: 0.8 }

            Item {
                width: parent.width
                height: parent.height * 0.32
                Text {
                    text: "TOTAL COST:"
                    color: "#A8B8CC"
                    font.pixelSize: parent.height * 0.18
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: parent.height * 0.08
                }
                Text {
                    text: "₹" + fuelModel.totalCost.toFixed(2)
                    color: "#E6E6E6"
                    font.bold: true
                    font.family: "Consolas"
                    font.pixelSize: Math.min(parent.width * 0.34, parent.height * 0.58)
                    fontSizeMode: Text.Fit
                    minimumPixelSize: 10
                    anchors.centerIn: parent
                    anchors.verticalCenterOffset: parent.height * 0.12
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Rectangle { width: parent.width; height: 1; color: "#2A4D69"; opacity: 0.8 }

            Item {
                width: parent.width
                height: parent.height * 0.32
                Text {
                    text: "PRICE PER LITER:"
                    color: "#A8B8CC"
                    font.pixelSize: parent.height * 0.18
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: parent.height * 0.08
                }
                Text {
                    text: "₹" + fuelModel.pricePerLiter.toFixed(2) + "/L"
                    color: "#E6E6E6"
                    font.bold: true
                    font.family: "Consolas"
                    font.pixelSize: Math.min(parent.width * 0.30, parent.height * 0.52)
                    fontSizeMode: Text.Fit
                    minimumPixelSize: 10
                    anchors.centerIn: parent
                    anchors.verticalCenterOffset: parent.height * 0.12
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
    }
}