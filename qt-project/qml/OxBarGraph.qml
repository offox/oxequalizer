import QtQuick 2.0

Item {
    property string label
    property int ledHeight: 6
    property int value;

    Column {
        id: column

        width: parent.width

        spacing: 2

        anchors.top: parent.top
        anchors.topMargin: 10

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 19 ? "#FE0201" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 18 ? "#FE0201" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 17 ? "#FE0201" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 16 ? "#FE0201" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 15 ? "#FFBF03" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 14 ? "#FFBF03" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 13 ? "#FFBF03" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 12 ? "#FFBF03" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 11 ? "#FEFE00" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 10 ? "#FEFE00" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 9 ? "#FEFE00" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 8 ? "#FEFE00" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 7 ? "#C1DF07": "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 6 ? "#C1DF07": "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 5 ? "#C1DF07": "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 4 ? "#C1DF07": "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 3 ? "#07FC09" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

           color: value > 2 ? "#07FC09" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 1 ? "#07FC09" : "black"
        }

        Rectangle {
            width: parent.width
            height: ledHeight

            color: value > 0 ? "#07FC09" : "black"
        }
    }

    Text {
        width: parent.width
        height: 20

        text: label
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 10
        color: "white"

        anchors.top: column.bottom
        anchors.topMargin: 10
    }
}
