import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

import ru.fo.dialcore 1.0
import ru.fo.dial 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: sender
        text: "Отправить"
        onClicked: {
            core.sendData(backLeftSpinBox.realValue, centerLeftSpinBox.realValue, forwardLeftSpinBox.realValue,
                          backRightSpinBox.realValue, centerRightSpinBox.realValue, forwardRightSpinBox.realValue)
        }
    }

    TextField {
        id: ipField
        anchors.left: sender.right
        anchors.leftMargin: 20
        width: 200
        placeholderText : "IP"
    }

    Rectangle {
        width: height
        height: 20
        radius: width
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10
        color: "red" //smth ? "green" : "red"
    }

    Column {
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        DoubleSpinBox {
            id: forwardLeftSpinBox
            width: 150
            height: 50
        }
        DoubleSpinBox {
            id: centerLeftSpinBox
            width: 150
            height: 50
        }
        DoubleSpinBox {
            id: backLeftSpinBox
            width: 150
            height: 50
        }
    }

    Column {
        spacing: 40
        anchors.centerIn: parent
        Row {
            spacing: 80
            Text {
                id: forwardLeft
                text: core.data["LF"] ? core.data["LF"] : 0
                font.pixelSize: 20
            }
            Text {
                id: forwardRight
                text: core.data["RF"] ? core.data["RF"] : 0
                font.pixelSize: 20
            }
        }
        Row {
            spacing: 80
            Text {
                id: centerLeft
                text: core.data["LC"] ? core.data["LC"] : 0
                font.pixelSize: 20
            }
            Text {
                id: centerRight
                text: core.data["RC"] ? core.data["RC"] : 0
                font.pixelSize: 20
            }
        }
        Row {
            spacing: 80
            Text {
                id: backLeft
                text: core.data["LB"] ? core.data["LB"] : 0
                font.pixelSize: 20
            }
            Text {
                id: backRight
                text: core.data["RB"] ? core.data["RB"] : 0
                font.pixelSize: 20
            }
        }
    }

    Column {
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        DoubleSpinBox {
            id: forwardRightSpinBox
            width: 150
            height: 50
        }
        DoubleSpinBox {
            id: centerRightSpinBox
            width: 150
            height: 50
        }
        DoubleSpinBox {
            id: backRightSpinBox
            width: 150
            height: 50
        }
    }

//    DialModel {
//        id: model
//    }

//    Loader {
//        id: loader
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.horizontalCenter: parent.horizontalCenter
//    }

//    FODial {
//        id: dial
//        dialModel: model
//        anchors.right: parent.right
//        anchors.bottom: parent.bottom
//        onIndexChanged: {
//            loader.source = model.data(model.index(currentIndex, 0), 258)
//        }
//    }

}
