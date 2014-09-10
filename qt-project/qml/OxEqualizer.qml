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
            onValueChanged: {
                oxEqualizer.setGain31(value)
            }
        }

        OxSlider {
            id: slider62

            value: value62
            onValueChanged: {
                oxEqualizer.setGain62(value)
            }
        }

        OxSlider {
            id: slider125

            value: value125
            onValueChanged: {
                oxEqualizer.setGain125(value)
            }
        }

        OxSlider {
            id: slider250

            value: value250
            onValueChanged: {
                oxEqualizer.setGain250(value)
            }
        }

        OxSlider {
            id: slider500

            value: value500
            onValueChanged: {
                oxEqualizer.setGain500(value)
            }
        }

        OxSlider {
            id: slider1k

            value: value1k
            onValueChanged: {
                oxEqualizer.setGain1k(value)
            }
        }

        OxSlider {
            id: slider2k

            value: value2k
            onValueChanged: {
                oxEqualizer.setGain2k(value)
            }
        }

        OxSlider {
            id: slider4k

            value: value4k
            onValueChanged: {
                oxEqualizer.setGain4k(value)
            }
        }

        OxSlider {
            id: slider8k

            value: value8k
            onValueChanged: {
                oxEqualizer.setGain8k(value)
            }
        }

        OxSlider {
            id: slider16k

            value: value16k
            onValueChanged: {
                oxEqualizer.setGain16k(value)
            }
        }
    }
}
