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

    SplitView {
        orientation: "Vertical"
        id: listsView
        anchors.fill: parent

        Item {
            SplitView.preferredHeight: listsView.height / 2



            SplitView {
                anchors.fill: parent
                id: dbView

                Item {
                    SplitView.preferredWidth: dbView.width / 3

                    ListView {
                        anchors.fill: parent
                        model: ["artist1", "artist2", "artist3"]
                        delegate: Rectangle {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            height: txt.contentHeight

                            Text {
                                id: txt
                                text: modelData
                            }
                        }
                    }
                }

                Item {
                    SplitView.preferredWidth: dbView.width / 3

                    Rectangle {
                        anchors.fill: parent
                        color: "#00ff00"
                    }
                }

                Item {

                    Rectangle {
                        anchors.fill: parent
                        color: "#0000ff"
                    }

                }
            }
        }

        Item {
            Rectangle {
                anchors.fill: parent
                color: "#aa0cdd"
            }
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:55;anchors_y:26}
}
##^##*/
