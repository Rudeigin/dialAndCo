import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Item {
//    anchors.verticalCenter: parent.verticalCenter
//    anchors.horizontalCenter: parent.horizontalCenter
    height: 150
    width: 600
    GridLayout {
        id: grid
        columns: 4
        rowSpacing: 4
        columnSpacing: 4
        //1 строка
        FloatSpinBox {
            id: spin1
        }
        Text {
            id: field1
            width: FloatSpinBox.width
            height: FloatSpinBox.height
            text: "///"
        }
        Text {
            id: field4
            width: FloatSpinBox.width
            height: FloatSpinBox.height
            text: "///"
        }
        FloatSpinBox {
            id: spin4
        }

        //2 строка
        FloatSpinBox {
            id: spin2
        }
        Text {
            id: field2
            width: FloatSpinBox.width
            height: FloatSpinBox.height
            text: "///"
        }
        Text {
            id: field5
            width: FloatSpinBox.width
            height: FloatSpinBox.height
            text: "///"
        }
        FloatSpinBox {
            id: spin5
        }

        //3 строка
        FloatSpinBox {
            id: spin3
        }
        Text {
            id: field3
            width: FloatSpinBox.width
            height: FloatSpinBox.height
            text: "///////"
        }
        Text {
            id: field6
            width: FloatSpinBox.width
            height: FloatSpinBox.height
            text: "///"
        }
        FloatSpinBox {
            id: spin6
        }
    }
}
