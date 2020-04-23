import QtQuick 2.12
import QtQuick.Controls 2.13

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QTunes")

    header: ToolBar {
        ToolButton {
            id: connectDrawerButton
            icon.source: "images/bars-solid.svg"
            onClicked: {
                if (connectDrawer.visible) {
                    connectDrawer.close()
                } else {
                    connectDrawer.open()
                }
            }

            hoverEnabled: true
            ToolTip.text: qsTr("Connection settings")
            ToolTip.visible: hovered
        }
    }

    Drawer {
        y: header.height
        id: connectDrawer
        Connection {
            id: qTunes
            anchors.fill: parent
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:55;anchors_y:26}
}
##^##*/
