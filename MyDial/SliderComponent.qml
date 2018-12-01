import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Item {
//    anchors.verticalCenter: parent.verticalCenter
//    anchors.horizontalCenter: parent.horizontalCenter
    height: 250
    width: 100
    Slider {
        id: slider1
        from: 0
        value: 2.5
        to: 5
        stepSize: 0.1
        orientation: Qt.Vertical
        onValueChanged: if(box.checked) slider2.value = value
    }
    Slider {
        id: slider2
        from: 0
        value: 2.5
        to: 5
        stepSize: 0.1
        orientation: Qt.Vertical
        anchors.left: slider1.right
        anchors.margins: 10
        onValueChanged: if(box.checked) slider1.value = value
    }
    CheckBox {
        id: box
        checked: false
        anchors.top: slider1.bottom
    }
}
