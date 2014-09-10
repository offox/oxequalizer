import QtQuick 2.0

Rectangle {
    property double value31
    property double value62
    property double value125
    property double value250
    property double value500
    property double value1k
    property double value2k
    property double value4k
    property double value8k
    property double value16k

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
