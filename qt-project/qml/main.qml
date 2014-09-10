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
            //controller.setAudioUrl(audioUrl)
            controller.loadFile(audioUrl)
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

            value31: oxVuIn.value31
            value62: oxVuIn.value62
            value125: oxVuIn.value125
            value250: oxVuIn.value250
            value500: oxVuIn.value500
            value1k: oxVuIn.value1k
            value2k: oxVuIn.value2k
            value4k: oxVuIn.value4k
            value8k: oxVuIn.value8k
            value16k: oxVuIn.value16k
        }

        OxVu {
            id: vuOut

            width: 280
            height: 200

            value31: oxVuOut.value31
            value62: oxVuOut.value62
            value125: oxVuOut.value125
            value250: oxVuOut.value250
            value500: oxVuOut.value500
            value1k: oxVuOut.value1k
            value2k: oxVuOut.value2k
            value4k: oxVuOut.value4k
            value8k: oxVuOut.value8k
            value16k: oxVuOut.value16k
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

        OxEqualizer {
            id: mixer

            width: 280
            height: 200
        }
    }
}
