import QtQuick 2.12
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QTunes")

    header: ToolBar {
        RowLayout {
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

            ToolButton {
                id: playButton
                icon.source: "images/play-solid.svg"
                hoverEnabled: true
                ToolTip.text: qsTr("Play")
                ToolTip.visible: hovered
            }

            ToolButton {
                id: pauseButton
                icon.source: "images/pause-solid.svg"
                hoverEnabled: true
                ToolTip.text: qsTr("Pause")
                ToolTip.visible: hovered
            }


            ToolButton {
                id: prevButton
                icon.source: "images/step-backward-solid.svg"
                hoverEnabled: true
                ToolTip.text: qsTr("Previous")
                ToolTip.visible: hovered
            }

            ToolButton {
                id: nextButton
                icon.source: "images/step-forward-solid.svg"
                hoverEnabled: true
                ToolTip.text: qsTr("Next")
                ToolTip.visible: hovered
            }
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

                    ListModel {
                        id: artistsModel
                        ListElement {value: "artist 1"}
                        ListElement {value: "artist 2"}
                        ListElement {value: "artist 3"}
                    }

                    Component {
                        id: dlg
                        Text {
                            text: value
                        }
                    }

                    ListView {
                        anchors.fill: parent
                        model: artistsModel
                        delegate: dlg
                    }
                }

                Item {
                    SplitView.preferredWidth: dbView.width / 3

                    ListModel {
                        id: albumsModel
                        ListElement {value: "album 1"}
                        ListElement {value: "album 2"}
                        ListElement {value: "album 3"}
                    }

                    ListView {
                        anchors.fill: parent
                        model: albumsModel
                        delegate: dlg
                    }
                }

                Item {

                    ListModel {
                        id: songsModel
                        ListElement {value: "song 1"}
                        ListElement {value: "song 2"}
                        ListElement {value: "song 3"}
                    }

                    ListView {
                        anchors.fill: parent
                        model: songsModel
                        delegate: dlg
                    }

                }
            }
        }

        Item {

            ListModel {
                id: playlistModel
                ListElement {value: "song 1"}
                ListElement {value: "song 2"}
                ListElement {value: "song 3"}
            }

            ListView {
                anchors.fill: parent
                model: playlistModel
                delegate: dlg
            }

        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:55;anchors_y:26}
}
##^##*/
