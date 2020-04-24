import QtQuick 2.12
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12

ApplicationWindow {
    id: window
    visible: true
    width: 800
    height: 480
    title: qsTr("QTunes")

    header: ToolBar {

        ColumnLayout {
            anchors.fill: parent

            RowLayout {
                Layout.fillWidth: true
                ToolButton {
                    id: connectDrawerButton
                    icon.source: "images/menu-24px.svg"
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
                    icon.source: "images/play_arrow-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Play")
                    ToolTip.visible: hovered
                }

                ToolButton {
                    id: pauseButton
                    icon.source: "images/pause-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Pause")
                    ToolTip.visible: hovered
                }

                ToolButton {
                    id: stopButton
                    icon.source: "images/stop-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Stop")
                    ToolTip.visible: hovered
                }



                ToolButton {
                    id: prevButton
                    icon.source: "images/skip_previous-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Previous")
                    ToolTip.visible: hovered
                }

                ToolButton {
                    id: nextButton
                    icon.source: "images/skip_next-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Next")
                    ToolTip.visible: hovered
                }

                CheckBox {
                    id: randomCheck
                    text: "Random"
                }


                CheckBox {
                    id: repeatCheck
                    text: "Repeat"
                }

                CheckBox {
                    id: singleCheck
                    text: "Single"
                }
            }

            Slider {
                id: songSlider
                Layout.fillWidth: true
            }
        }
    }


    Drawer {
        y: header.height
        id: connectDrawer
        height: window.height - header.height
        width: window.width / 3
        Rectangle {
            anchors.fill: parent;

            ColumnLayout {
                id: connectionColumn
                anchors.fill: parent
                opacity: 1

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
