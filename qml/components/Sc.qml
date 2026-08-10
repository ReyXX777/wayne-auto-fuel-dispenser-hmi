import QtQuick 2.15
HMICard {
    title: "MASTER"
    Text {
        anchors.centerIn: parent; horizontalAlignment: Text.AlignHCenter; color: "#FFEB3B"; font.bold: true; font.pixelSize: parent.height*0.12
        text: {
            if (fuelModel.selectedGrade === -1) return "WELCOME\nPlease select fuel";
            if (fuelModel.presetAmount < 0.01) return "Grade: " + fuelModel.selectedGrade + "\nEnter amount...";
            if (fuelModel.currentVolume < fuelModel.targetVolume - 0.001 && fuelModel.targetVolume > 0) return "DISPENSING...\n" + fuelModel.currentVolume.toFixed(2) + " / " + fuelModel.targetVolume.toFixed(2) + " L";
            if (fuelModel.currentVolume >= fuelModel.targetVolume - 0.001 && fuelModel.targetVolume > 0) return "COMPLETE\nThank you!";
            return "READY ₹" + fuelModel.presetAmount;
        }
    }
}