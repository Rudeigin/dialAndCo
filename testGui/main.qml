import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

import ru.fo.dialcore 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function send() {
        core.sendData(backLeftSpinBox.realValue, centerLeftSpinBox.realValue, forwardLeftSpinBox.realValue,
                      backRightSpinBox.realValue, centerRightSpinBox.realValue, forwardRightSpinBox.realValue)
    }

    TextField {
        id: ipField
//        anchors.leftMargin: 20
        width: 200
        placeholderText : "IP"
    }

    Button {
        id: sendIp
        anchors.left: ipField.right
        anchors.leftMargin: 10
        text: "Принять"
        onClicked: {
            core.setIp(ipField.text)
        }
    }

    Rectangle {
        width: height
        height: 20
        radius: width
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10
        color: core.connected ? "green" : "red"
    }

    Column {
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        DoubleSpinBox {
            id: forwardLeftSpinBox
            width: 150
            height: 50
            onValueChanged: root.send()
        }
        DoubleSpinBox {
            id: centerLeftSpinBox
            width: 150
            height: 50
            onValueChanged: root.send()
        }
        DoubleSpinBox {
            id: backLeftSpinBox
            width: 150
            height: 50
            onValueChanged: root.send()
        }
    }

    Column {
        spacing: 40
        anchors.centerIn: parent
        Row {
            spacing: 40
            Text {
                id: forwardLeft
                text: core.data["LF"] ? core.data["LF"] : 0
                font.pixelSize: 20
                elide: Text.ElideRight
                width: 100
            }
            Text {
                id: forwardRight
                text: core.data["RF"] ? core.data["RF"] : 0
                font.pixelSize: 20
                elide: Text.ElideRight
                width: 100
            }
        }
        Row {
            spacing: 40
            Text {
                id: centerLeft
                text: core.data["LC"] ? core.data["LC"] : 0
                font.pixelSize: 20
                elide: Text.ElideRight
                width: 100
            }
            Text {
                id: centerRight
                text: core.data["RC"] ? core.data["RC"] : 0
                font.pixelSize: 20
                elide: Text.ElideRight
                width: 100
            }
        }
        Row {
            spacing: 40
            Text {
                id: backLeft
                text: core.data["LB"] ? core.data["LB"] : 0
                font.pixelSize: 20
                elide: Text.ElideRight
                width: 100
            }
            Text {
                id: backRight
                text: core.data["RB"] ? core.data["RB"] : 0
                font.pixelSize: 20
                elide: Text.ElideRight
                width: 100
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
            onValueChanged: root.send()
        }
        DoubleSpinBox {
            id: centerRightSpinBox
            width: 150
            height: 50
            onValueChanged: root.send()
        }
        DoubleSpinBox {
            id: backRightSpinBox
            width: 150
            height: 50
            onValueChanged: root.send()
        }
    }
}
