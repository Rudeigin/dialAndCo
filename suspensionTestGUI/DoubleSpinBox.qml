import QtQuick 2.0
import QtQuick.Controls 2.0

SpinBox {
    from: -1
    value: 25
    to: 51

    property real realValue: value / 10

    validator: DoubleValidator {
        bottom: Math.min(from, to)
        top:  Math.max(from, to)
    }

    textFromValue: function(value, locale) {
        return Number(realValue).toLocaleString()
    }

    valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 10
    }
}
