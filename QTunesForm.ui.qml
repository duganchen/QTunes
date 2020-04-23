import QtQuick 2.4
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3

Item {
    width: 400
    height: 400

    ColumnLayout {
        id: connectionColumn
        anchors.fill: parent

        Label {
            id: hostLabel
            text: qsTr("Host")
            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
        }


        TextField {
            id: hostText
            text: qsTr("localhost")
            Layout.fillWidth: true
        }


        Label {
            id: hostValidationLabel
            text: qsTr("Host validation message")
        }

        Label {
            id: portLabel
            text: qsTr("Port")
        }

        TextField {
            id: portText
            text: qsTr("6600")
            Layout.fillWidth: true
        }


        Label {
            id: portValidationLabel
            text: qsTr("Port validation message")
        }


        RowLayout {
            id: connectRow
            width: 100
            height: 100


            Button {
                id: connectButton
                text: qsTr("Connect")
            }

            BusyIndicator {
                id: connectBusy
            }
        }


    }
}

/*##^##
Designer {
    D{i:1;anchors_height:100;anchors_width:100;anchors_x:5;anchors_y:136}
}
##^##*/
