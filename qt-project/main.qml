import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height

    title: qsTr("OxEquilizer 10 band frequencies")

    property string audioUrl

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { action: openAction }
            MenuItem { action: quitAction }
        }

        Menu {
            title: "About"
            MenuItem { action: aboutAction }
        }
    }

    Action {
        id: openAction
        text: "Open..."
        onTriggered: fileDialog.open()
    }

    Action {
        id: quitAction
        text: "About"
        onTriggered: aboutDialog
    }

    Action {
        id: aboutAction
        text: "About"
        onTriggered: aboutDialog.open()
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            audioUrl = fileDialog.fileUrl
            controller.setAudioUrl(audioUrl)
        }
        onRejected: {
            console.log("Canceled")
        }
    }

    MessageDialog {
        id: aboutDialog
    }

    Grid {
        columns: 2
        spacing: 10

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        OxVu {
            id: vuIn

            width: 280
            height: 200

            value31: 10
            value62: 12
            value125: 3
            value250: 12
            value500: 18
            value1k: 6
            value2k: 15
            value4k: 2
            value8k: 8
            value16k: 13
        }

        OxVu {
            id: vuOut
            width: 280
            height: 200
        }

        Item {
            width: 280
            height: 200

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                spacing: 20

                Button {
                    width: 60
                    height: 60

                    iconSource: "images/play.png"

                    onClicked: {
                        controller.play()
                    }
                }

                Button {
                    width: 60
                    height: 60

                    iconSource: "images/stop.png"

                    onClicked: {
                        controller.stop()
                    }
                }

                Button {
                    width: 60
                    height: 60

                    iconSource: "images/pause.png"
                }
            }
        }

        OxMixer {
            id: mixer

            width: 280
            height: 200
        }
    }
}
