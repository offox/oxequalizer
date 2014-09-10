import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2


Slider {
    visible: true
    orientation: Qt.Vertical

    maximumValue: 1
    minimumValue: 0
    value: 0

    style: SliderStyle {
         groove: Rectangle {
             implicitWidth: 180
             implicitHeight: 5
             color: "gray"
             radius: 8
         }
         handle: Image {
             anchors.centerIn: parent
             source: "images/slider-handle.jpg"
         }
     }
}
