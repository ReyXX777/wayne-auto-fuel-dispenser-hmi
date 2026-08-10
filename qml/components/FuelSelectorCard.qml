import QtQuick 2.15

HMICard {
    title: "SELECT FUEL"

    property var fuelData: [
        { grade: 0, label: "PETROL",  icon: "qrc:/assets/drop_petrol.svg",  glow: "#E0E0E0" },
        { grade: 1, label: "E20",     icon: "qrc:/assets/drop_e20.svg",     glow: "#8BC34A" },
        { grade: 2, label: "E80",     icon: "qrc:/assets/drop_e80.svg",     glow: "#FF5722" },
        { grade: 3, label: "PREMIUM", icon: "qrc:/assets/drop_premium.svg", glow: "#FF5252" },
        { grade: 4, label: "DIESEL",  icon: "qrc:/assets/drop_diesel.svg",  glow: "#66BB6A" }
    ]

    Grid {
        anchors.fill: parent
        anchors.margins: parent.width * 0.02
        columns: 3
        columnSpacing: parent.width * 0.04
        rowSpacing: parent.height * 0.05

        Repeater {
            model: fuelData
            delegate: Item {
                width: (parent.width - parent.columnSpacing * 2) / 3
                height: (parent.height - parent.rowSpacing) / 2

                property bool isSelected: fuelModel.selectedGrade === modelData.grade
                property bool isSimPressed: fuelModel.simulatedFuelIndex === index

                Rectangle {
                    id: bg
                    anchors.fill: parent
                    radius: parent.width * 0.12
                    color: isSelected || isSimPressed ? "#1A3C5A" : "#0F2235"
                    border.color: isSelected || isSimPressed ? modelData.glow : "#1E3A52"
                    border.width: isSelected || isSimPressed ? 2 : 1
                    clip: true
                }

                Column {
                    anchors.fill: parent
                    anchors.margins: parent.width * 0.06
                    spacing: 0

                    Item {
                        width: parent.width
                        height: parent.height * 0.70
                        Image {
                            source: modelData.icon
                            anchors.centerIn: parent
                            width: Math.min(parent.width * 0.75, parent.height * 0.9)
                            height: Math.min(parent.width * 0.75, parent.height * 0.9) * 1.2
                            fillMode: Image.PreserveAspectFit
                            scale: isSelected || isSimPressed ? 1.08 : 1.0
                            Behavior on scale { NumberAnimation { duration: 180 } }
                        }
                    }

                    Item {
                        width: parent.width
                        height: parent.height * 0.30
                        Text {
                            anchors.fill: parent
                            text: modelData.label
                            color: isSelected || isSimPressed ? "#E6E6E6" : "#A8B8CC"
                            font.bold: true
                            font.family: "Consolas"
                            font.pixelSize: parent.height * 0.48
                            minimumPixelSize: 6
                            fontSizeMode: Text.Fit
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignTop
                            wrapMode: Text.NoWrap
                            elide: Text.ElideRight
                        }
                    }
                }
            }
        }

        Item {
            width: (parent.width - parent.columnSpacing * 2) / 3
            height: (parent.height - parent.rowSpacing) / 2
        }
    }
}