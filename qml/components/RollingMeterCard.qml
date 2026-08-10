import QtQuick 2.15

HMICard {
    title: "DELIVERY"

    property int displayVal: Math.floor(fuelModel.currentVolume * 100 + 0.5)
    property string sVal: displayVal < 10? "000" + displayVal : displayVal < 100? "00" + displayVal : displayVal < 1000? "0" + displayVal : displayVal < 10000? "" + displayVal : "9999"

    Item {
        anchors.fill: parent
        anchors.margins: parent.width * 0.04

        Rectangle {
            id: outerFrame
            width: parent.width * 0.88
            height: parent.height * 0.52
            radius: parent.height * 0.08
            color: "#2A4D69"
            anchors.centerIn: parent

            Rectangle {
                anchors.fill: parent
                anchors.margins: parent.height * 0.12
                radius: parent.height * 0.15
                color: "#080808"
                border.color: "#000"
                border.width: 1

                Row {
                    anchors.centerIn: parent
                    spacing: parent.width * 0.015
                    width: parent.width * 0.92
                    height: parent.height * 0.82

                    Repeater {
                        model: 4
                        delegate: Rectangle {
                            width: (parent.width - parent.spacing * 3) / 4
                            height: parent.height
                            radius: width * 0.12
                            color: "#111111"
                            border.color: "#222"
                            border.width: 1

                            Rectangle {
                                width: parent.width
                                height: parent.height * 0.22
                                radius: parent.radius
                                color: "#2A2A2A"
                                opacity: 0.6
                            }

                            Text {
                                anchors.centerIn: parent
                                text: sVal[index]
                                color: "#F0F0F0"
                                font.bold: true
                                font.family: "Consolas"
                                font.pixelSize: parent.height * 0.62
                                fontSizeMode: Text.Fit
                                minimumPixelSize: 6
                            }

                            Rectangle {
                                width: parent.width * 0.4
                                height: parent.height * 0.04
                                radius: 2
                                color: "#555"
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: parent.height * 0.08
                            }
                        }
                    }
                }
            }
        }

        Row {
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.bottomMargin: parent.height * 0.04
            anchors.rightMargin: parent.width * 0.02
            spacing: parent.width * 0.06
            Text {
                text: "ACTIVE"
                color: "#C8D67A"
                font.pixelSize: parent.parent.height * 0.08
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: parent.parent.height * 0.09
                height: width
                radius: width / 2
                color: "#E6EB00"
                anchors.verticalCenter: parent.verticalCenter
                SequentialAnimation on opacity {
                    running: true
                    loops: Animation.Infinite
                    NumberAnimation { from: 0.7; to: 1.0; duration: 700 }
                    NumberAnimation { from: 1.0; to: 0.7; duration: 700 }
                }
            }
        }
    }
}