import QtQuick 2.15

HMICard {
    id: payRoot
    title: "AMOUNT & PAYMENT"

    property bool canPay: fuelModel.targetVolume > 0.001 && fuelModel.currentVolume >= fuelModel.targetVolume - 0.01
    property bool showQr: false
    property bool showSuccess: false

    onCanPayChanged: {
        if (canPay) qrTimer.start()
    }

    Row {
        anchors.fill: parent
        anchors.margins: parent.width * 0.01
        spacing: parent.width * 0.04

        Column {
            width: parent.width * 0.62
            height: parent.height
            spacing: parent.height * 0.03

            Rectangle {
                width: parent.width
                height: parent.height * 0.14
                radius: height * 0.25
                color: "#050A10"
                border.color: "#2A4D69"
                border.width: 1
                clip: true
                Text {
                    anchors.centerIn: parent
                    text: "₹ " + fuelModel.presetAmount.toFixed(2)
                    color: "#4FC3F7"
                    font.bold: true
                    font.family: "Consolas"
                    font.pixelSize: parent.height * 0.52
                    minimumPixelSize: 8
                    fontSizeMode: Text.Fit
                    width: parent.width * 0.9
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Grid {
                width: parent.width
                height: parent.height * 0.83
                columns: 3
                columnSpacing: parent.width * 0.03
                rowSpacing: parent.height * 0.025

                Repeater {
                    model: ["1", "2", "3", "4", "5", "6", "7", "8", "9", "Clr", "0", "Ent"]
                    delegate: Rectangle {
                        width: (parent.width - parent.columnSpacing * 2) / 3
                        height: (parent.height - parent.rowSpacing * 3) / 4
                        radius: width * 0.18
                        property bool isSimPressed: fuelModel.simulatedKeypadIndex === index
                        color: isSimPressed ? "#4FC3F7" : "#0F2235"
                        border.color: isSimPressed ? "#4FC3F7" : "#1E3A52"
                        border.width: isSimPressed ? 2 : 1
                        clip: true

                        Text {
                            anchors.fill: parent
                            anchors.margins: 2
                            text: modelData
                            color: isSimPressed ? "#000" : (modelData === "Ent" ? "#4CAF50" : (modelData === "Clr" ? "#FF5252" : "#A8B8CC"))
                            font.bold: true
                            font.family: "Consolas"
                            font.pixelSize: parent.height * 0.42
                            minimumPixelSize: 6
                            fontSizeMode: Text.Fit
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }
        }

        Column {
            width: parent.width * 0.34
            height: parent.height
            spacing: parent.height * 0.03

            Repeater {
                model: [
                    {icon: "qrc:/assets/icon_tap_card.svg", label: "TAP"},
                    {icon: "qrc:/assets/icon_insert_chip.svg", label: "CHIP"},
                    {icon: "qrc:/assets/icon_pay.svg", label: "PAY"}
                ]
                delegate: Rectangle {
                    width: parent.width
                    height: (parent.height - parent.spacing * 2) / 3
                    radius: width * 0.12
                    property bool isPay: modelData.label === "PAY"
                    color: isPay && payRoot.canPay ? "#143D1A" : "#0B1A2A"
                    border.color: isPay && payRoot.canPay ? "#4CAF50" : "#2A4D69"
                    border.width: isPay && payRoot.canPay ? 2 : 1
                    opacity: isPay && !payRoot.canPay ? 0.4 : 1.0
                    clip: true

                    Column {
                        anchors.fill: parent
                        anchors.margins: parent.width * 0.08
                        spacing: 0
                        Item {
                            width: parent.width
                            height: parent.height * 0.66
                            Image {
                                source: modelData.icon
                                anchors.centerIn: parent
                                width: Math.min(parent.width * 0.7, parent.height * 0.9)
                                height: width
                                fillMode: Image.PreserveAspectFit
                            }
                        }
                        Item {
                            width: parent.width
                            height: parent.height * 0.34
                            Text {
                                anchors.fill: parent
                                text: modelData.label
                                color: isPay && payRoot.canPay ? "#4CAF50" : "#A8B8CC"
                                font.bold: isPay && payRoot.canPay
                                font.family: "Consolas"
                                font.pixelSize: parent.height * 0.5
                                minimumPixelSize: 6
                                fontSizeMode: Text.Fit
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignTop
                            }
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        anchors.fill: parent
        radius: 8
        color: "#F5050A10"
        border.color: "#4CAF50"
        border.width: 2
        visible: payRoot.showQr
        z: 100
        Column {
            anchors.centerIn: parent
            spacing: parent.height * 0.08
            width: parent.width * 0.6
            Rectangle {
                width: parent.width * 0.6
                height: width
                color: "white"
                radius: 8
                anchors.horizontalCenter: parent.horizontalCenter
                Image {
                    source: "qrc:/assets/icon_qr.svg"
                    anchors.fill: parent
                    anchors.margins: parent.width * 0.08
                    fillMode: Image.PreserveAspectFit
                }
                Rectangle {
                    width: parent.width
                    height: 3
                    color: "#FF0000"
                    y: 0
                    SequentialAnimation on y {
                        running: payRoot.showQr
                        loops: Animation.Infinite
                        NumberAnimation { from: 0; to: 107; duration: 800; easing.type: Easing.InOutQuad }
                        NumberAnimation { from: 107; to: 0; duration: 800; easing.type: Easing.InOutQuad }
                    }
                }
            }
            Text {
                text: "SCANNING QR\n₹ " + fuelModel.totalCost.toFixed(2)
                color: "white"
                font.bold: true
                font.family: "Consolas"
                font.pixelSize: parent.parent.height * 0.08
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Rectangle {
        anchors.fill: parent
        radius: 8
        color: "#FF0A2A10"
        border.color: "#4CAF50"
        border.width: 2
        visible: payRoot.showSuccess
        z: 101
        Column {
            anchors.centerIn: parent
            spacing: 8
            Text { text: "✓"; color: "#4CAF50"; font.bold: true; font.pixelSize: 48; font.family: "Consolas"; anchors.horizontalCenter: parent.horizontalCenter }
            Text { text: "PAYMENT COMPLETE"; color: "#4CAF50"; font.bold: true; font.family: "Consolas"; font.pixelSize: 14; anchors.horizontalCenter: parent.horizontalCenter }
            Text { text: "₹ " + fuelModel.totalCost.toFixed(2) + " PAID"; color: "white"; font.family: "Consolas"; font.pixelSize: 10; anchors.horizontalCenter: parent.horizontalCenter }
        }
    }

    Timer { id: qrTimer; interval: 800; onTriggered: { payRoot.showQr = true; successTimer.start() } }
    Timer { id: successTimer; interval: 1200; onTriggered: { payRoot.showQr = false; payRoot.showSuccess = true; homeTimer.start() } }
    Timer { id: homeTimer; interval: 1800; onTriggered: { payRoot.showSuccess = false; payRoot.showQr = false; dispenserController.startAutomatedDemo() } }
}