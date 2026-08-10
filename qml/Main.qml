import QtQuick 2.15
import QtQuick.Window 2.15
import "components"

Window {
    id: root
    width: 1024
    height: 768
    visible: true
    title: "Fuel Dispenser HMI - AUTO"
    color: "#050A10"

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#0A192F" }
            GradientStop { position: 1.0; color: "#02060D" }
        }
    }

    Rectangle {
        id: header
        width: parent.width
        height: parent.height * 0.062
        anchors.top: parent.top
        color: "#0D2B4A"
        border.color: "#1E4A6B"
        border.width: 1

        Row {
            anchors.fill: parent
            anchors.leftMargin: parent.width * 0.012
            anchors.rightMargin: parent.width * 0.012

            Item {
                width: parent.width * 0.40
                height: parent.height

                Row {
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: parent.parent.height * 0.25

                    Rectangle {
                        width: header.height * 0.52
                        height: width
                        radius: width / 2
                        color: "#2E7D32"
                        anchors.verticalCenter: parent.verticalCenter
                        Text {
                            anchors.centerIn: parent
                            text: "✓"
                            color: "white"
                            font.bold: true
                            font.pixelSize: parent.height * 0.65
                        }
                    }

                    Text {
                        text: "SYSTEM STATUS: "
                        color: "#D0D8E0"
                        font.family: "Consolas"
                        font.pixelSize: header.height * 0.32
                        minimumPixelSize: 7
                        fontSizeMode: Text.Fit
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        
                        text: fuelModel ? fuelModel.statusText ? fuelModel.statusText : "DELIVERING FUEL" : "DELIVERING FUEL"
                        color: "#8BC34A"
                        font.family: "Consolas"
                        font.bold: true
                        font.pixelSize: header.height * 0.32
                        minimumPixelSize: 7
                        fontSizeMode: Text.Fit
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }

            Item {
                width: parent.width * 0.35
                height: parent.height
                Text {
                    anchors.centerIn: parent
                    text: "STATION 1"
                    color: "#E6E6E6"
                    font.family: "Consolas"
                    font.bold: true
                    font.pixelSize: header.height * 0.38
                    minimumPixelSize: 8
                    fontSizeMode: Text.Fit
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Item {
                width: parent.width * 0.25
                height: parent.height
                Text {
                    id: dateText
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    text: "DATE 1/2023 | 11:59 AM"
                    color: "#A8B8CC"
                    font.family: "Consolas"
                    font.pixelSize: header.height * 0.30
                    minimumPixelSize: 7
                    fontSizeMode: Text.Fit
                    horizontalAlignment: Text.AlignRight

                    Timer {
                        interval: 1000; running: true; repeat: true
                        onTriggered: {
                            var d = new Date()
                            var h = d.getHours() % 12
                            if (h === 0) h = 12
                            var m = d.getMinutes()
                            if (m < 10) m = "0" + m
                            var ampm = d.getHours() >= 12 ? "PM" : "AM"
                            dateText.text = "DATE " + (d.getMonth()+1) + "/" + d.getFullYear() + " | " + h + ":" + m + " " + ampm
                        }
                    }
                }
            }
        }
    }

    Grid {
        id: mainGrid
        anchors.top: header.bottom
        anchors.topMargin: root.height * 0.01
        anchors.horizontalCenter: parent.horizontalCenter
        width: root.width * 0.98
        height: root.height * 0.92
        columns: 3
        rows: 2
        spacing: root.width * 0.01
        property real cellWidth: (width - (spacing*2))/3
        property real cellHeight: (height - spacing)/2
        FuelProgressCard { width: mainGrid.cellWidth; height: mainGrid.cellHeight }
        MeterReadingsCard { width: mainGrid.cellWidth; height: mainGrid.cellHeight }
        RollingMeterCard { width: mainGrid.cellWidth; height: mainGrid.cellHeight }
        FuelSelectorCard { width: mainGrid.cellWidth; height: mainGrid.cellHeight }
        StatusCard { width: mainGrid.cellWidth; height: mainGrid.cellHeight }
        PaymentCard { width: mainGrid.cellWidth; height: mainGrid.cellHeight }
    }
}