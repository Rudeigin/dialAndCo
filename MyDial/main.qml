import QtQuick 2.11
import QtQuick.Window 2.3
import models 1.0
import ru.fo.dial 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480

    DialModel {
        id: model
    }

    Loader {
        id: loader
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
//        onSourceChanged: console.log("я блять сработал")
    }

    FODial {
        id: dial
        dialModel: model
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onIndexChanged: {
            loader.source = model.data(model.index(currentIndex, 0), 258)
        }
    }
}
