import QtQuick 2.0

Rectangle {
    property int value31
    property int value62
    property int value125
    property int value250
    property int value500
    property int value1k
    property int value2k
    property int value4k
    property int value8k
    property int value16k

    color: "black"

    Row {
        spacing: 5

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        OxBarGraph {
            width: 22
            height: 200

            value: value31
            label: "31"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value62
            label: "62"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value125
            label: "125"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value250
            label: "250"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value500
            label: "500"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value1k
            label: "1k"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value2k
            label: "2k"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value4k
            label: "4k"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value8k
            label: "8k"
        }

        OxBarGraph {
            width: 22
            height: 200

            value: value16k
            label: "16k"
        }
    }
}
