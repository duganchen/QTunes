import QtQuick 2.4
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3

Item {
    width: 400
    height: 400

    GridLayout {
        id: connectionLayout
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        rows: 2
        columns: 2
        columnSpacing: 5
        rowSpacing: 5
        anchors.fill: parent

        Label {
            id: hostLabel
            text: qsTr("Host")
        }

        TextField {
            id: hostText
            text: qsTr("localhost")
            Layout.fillWidth: true
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
    }

}


/*##^##
Designer {
    D{i:1;anchors_height:100;anchors_width:100;anchors_x:126;anchors_y:23}
}
##^##*/

