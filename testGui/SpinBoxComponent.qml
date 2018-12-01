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
        DoubleSpinBox {
            id: leftTopBox
        }
        Text {
            id: leftTopText
            width: DoubleSpinBox.width
            height: DoubleSpinBox.height
            text: "///"
        }
        Text {
            id: rightTopText
            width: DoubleSpinBox.width
            height: DoubleSpinBox.height
            text: "///"
        }
        DoubleSpinBox {
            id: rightTopBox
        }

        //2 строка
        DoubleSpinBox {
            id: leftCentralBox
        }
        Text {
            id: leftCentralText
            width: DoubleSpinBox.width
            height: DoubleSpinBox.height
            text: "///////"
        }
        Text {
            id: rightCentralText
            width: DoubleSpinBox.width
            height: DoubleSpinBox.height
            text: "///"
        }
        DoubleSpinBox {
            id: rightCentralBox
        }

        //3 строка
        DoubleSpinBox {
            id: leftBottomBox
        }
        Text {
            id: leftBottomText
            width: DoubleSpinBox.width
            height: DoubleSpinBox.height
            text: "///"
        }
        Text {
            id: rightBottomText
            width: DoubleSpinBox.width
            height: DoubleSpinBox.height
            text: "///"
        }
        DoubleSpinBox {
            id: rightBottomBox
        }
    }
}
