import QtQuick 2.4
import QtQuick.Controls 2.13

Item {
    width: 400
    height: 400

    Grid {
        id: grid
        anchors.fill: parent
        rows: 2
        columns: 2
    }

    Label {
        id: hostLabel
        x: 69
        y: 74
        text: qsTr("Host")
    }

    TextField {
        id: hostText
        x: 138
        y: 63
        width: 254
        height: 40
        text: qsTr("localhost")
    }

    Label {
        id: portLabel
        x: 69
        y: 129
        text: qsTr("Port")
    }

    TextField {
        id: portText
        x: 138
        y: 118
        width: 254
        height: 40
        text: qsTr("6600")
    }
}

/*##^##
Designer {
    D{i:1;anchors_height:400;anchors_width:400;anchors_x:0;anchors_y:0}D{i:5;anchors_x:138;anchors_y:118}
}
##^##*/

