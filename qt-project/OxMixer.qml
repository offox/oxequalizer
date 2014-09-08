import QtQuick 2.0

Item {
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

    Row {
        spacing: 12

        anchors.centerIn: parent

        OxSlider {
            id: slider31

            value: value31
        }

        OxSlider {
            id: slider62

            value: value62
        }

        OxSlider {
            id: slider125

            value: value125
        }

        OxSlider {
            id: slider250

            value: value250
        }

        OxSlider {
            id: slider500

            value: value500
        }

        OxSlider {
            id: slider1k

            value: value1k
        }

        OxSlider {
            id: slider2k

            value: value2k
        }

        OxSlider {
            id: slider4k

            value: value4k
        }

        OxSlider {
            id: slider8k

            value: value8k
        }

        OxSlider {
            id: slider16k

            value: value16k
        }
    }
}
