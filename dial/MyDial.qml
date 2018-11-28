import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import ru.fo.dial 1.0
//import QtGraphicalEffects 1.0

Item {
    id: control
    width: 240
    height: 240
//    anchors.fill: parent

    //Угол между двумя элементами из модели
    property real segmentAngle: curveArc.sweepAngle / pathView.count
    //текущий элемент
    property int currentIndex: 0

    signal indexChanged(int index)

    property var dialModel: 5

    onCurrentIndexChanged: {
        control.indexChanged(currentIndex)
    }


    Dial {
        id: dial
        value: 0
        x: curveArc.radiusX * 0.2
        y: curveArc.radiusY * 0.2
        width: curveArc.radiusX * 1.6
        height: curveArc.radiusX * 1.6

        background: Image {
            id: img
            source: "icons/dial.png"
//            ColorOverlay {
//                anchors.fill: parent
//                color: "#703e7dcf"
//                source: parent
//            }
        }

        onPressedChanged: {
//диал от -140 до 140, поэтому 140 и 280
            control.currentIndex = Math.round((dial.angle + 140)/segmentAngle)

            if(control.currentIndex > pathView.count-1) currentIndex--

            value = control.currentIndex * segmentAngle / curveArc.sweepAngle
        }
    }

//    подсветка круга шкалы
//    Canvas {
//        contextType: "2d"
//        height: 400
//        width: 400
//        onPaint: {
//            context.strokeStyle = Qt.rgba(.4,.6,.8);
//            context.path = curve;
//            context.stroke();
//        }
//    }

    Path {
        id: curve
        PathAngleArc {
            id: curveArc
            radiusX: control.width / 2; radiusY: control.height / 2
            centerX: radiusX; centerY: radiusY
            startAngle: 130
            sweepAngle: 280
        }
    }

    PathView {
        id: pathView
        visible: true
        height: control.height
        width: control.width
        model: dialModel
        delegate: Item {
            width: icon.width
            height: icon.height
            Image {
                id: icon
                source: barIcon
                height: 15
                width: 15
            }

            MouseArea {
                anchors.fill: parent
                onClicked:{
                    dial.value = index * segmentAngle / curveArc.sweepAngle
                    control.currentIndex = index
                }
            }
        }
        path: curve
        interactive: false
    }
}
