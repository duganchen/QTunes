import QtQuick 2.12
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12


ApplicationWindow {
    visible: true
    width: 1024
    height: 480
    title: qsTr("QTunes")

    id: window

    ListDelegate {
        id: dlg
    }

    header: ToolBar {

        ColumnLayout {
            anchors.fill: parent

            RowLayout {
                Layout.fillWidth: true
                ToolButton {
                    icon.source: "images/play_arrow-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Play")
                    ToolTip.visible: hovered
                }

                ToolButton {
                    icon.source: "images/pause-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Pause")
                    ToolTip.visible: hovered
                }

                ToolButton {
                    icon.source: "images/stop-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Stop")
                    ToolTip.visible: hovered
                }



                ToolButton {
                    icon.source: "images/skip_previous-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Previous")
                    ToolTip.visible: hovered
                }

                ToolButton {
                    icon.source: "images/skip_next-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Next")
                    ToolTip.visible: hovered
                }

                CheckBox {
                    text: "Random"
                }


                CheckBox {
                    text: "Repeat"
                }

                CheckBox {
                    text: "Single"
                }
            }

            Slider {
                Layout.fillWidth: true
            }
        }
    }


    Drawer {
        y: header.height
        height: window.height - header.height
        width: window.width / 3
        id: connectDrawer
        Rectangle {
            anchors.fill: parent;

            ColumnLayout {
                anchors.fill: parent
                opacity: 1

                Label {
                    text: qsTr("Host")
                    Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                }


                TextField {
                    text: controller.host
                    validator: RegExpValidator {
                        // https://stackoverflow.com/a/106223/240515
                        regExp: /^(([a-zA-Z0-9]|[a-zA-Z0-9][a-zA-Z0-9\-]*[a-zA-Z0-9])\.)*([A-Za-z0-9]|[A-Za-z0-9][A-Za-z0-9\-]*[A-Za-z0-9])$/
                    }

                    onTextChanged: {
                        controller.host = hostText.text
                    }

                    Layout.fillWidth: true
                }


                Label {
                    text: qsTr("Host validation message")
                }

                Label {
                    text: qsTr("Port")
                }

                TextField {
                    text: controller.port
                    Layout.fillWidth: true
                    validator: IntValidator {
                        bottom: 1024
                        top: 65535

                    }
                    onTextChanged: {
                        controller.port = portText.text
                    }
                }


                Label {
                    text: qsTr("Port validation message")
                }


                RowLayout {
                    width: 100
                    height: 100


                    Button {
                        text: qsTr("Connect")
                        enabled: controller.connectEnabled;

                        onClicked: {
                            controller.connect()
                        }
                    }

                    BusyIndicator {
                        visible: controller.isConnecting;
                    }
                }

            }
        }
    }

    SplitView {
        orientation: "Horizontal"
        anchors.fill: parent


        SplitView {
            orientation: "Vertical"

            SplitView.preferredWidth: parent.width / 2

            SplitView {
                SplitView.preferredHeight: parent.height / 2
                orientation: "Horizontal"

                ColumnLayout {
                    SplitView.preferredWidth: parent.width / 3

                    ToolBar {
                        Layout.fillWidth: true
                    }
                    ScrollView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        clip: true

                        ListView {
                            model: tagModel
                            delegate: dlg
                        }
                    }
                }

                ColumnLayout {
                    SplitView.preferredWidth: parent.width / 3
                    ToolBar {
                        Layout.fillWidth: true
                    }

                    ScrollView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        ListView {
                            model: artistModel
                            delegate: dlg
                        }
                    }
                }

                ColumnLayout {
                    ToolBar {
                        Layout.fillWidth: true
                        RowLayout {
                            ToolButton {
                                icon.source: "images/playlist_add-24px.svg"
                                hoverEnabled: true
                                ToolTip.text: qsTr("Queue selected album")
                                ToolTip.visible: hovered
                                enabled: albumView.currentItem
                            }
                        }
                    }

                    ScrollView {
                        clip: true
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        ListView {
                            id: albumView
                            model: albumModel
                            delegate: dlg
                        }
                    }
                }
            }

            ColumnLayout {
                ToolBar {
                    Layout.fillWidth: true

                    RowLayout {
                        ToolButton {
                            icon.source: "images/delete-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Remove selected playlist")
                            ToolTip.visible: hovered
                            enabled: playlistView.currentItem
                        }

                        TextField {
                            id: playlistNewName
                        }

                        ToolButton {
                            icon.source: "images/edit-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Rename selected playlist")
                            ToolTip.visible: hovered

                            enabled: playlistNewName.text && playlistView.currentItem
                        }

                        ToolButton {
                            icon.source: "images/folder_open-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Load selected playlist into queue")
                            ToolTip.visible: hovered

                            enabled: playlistView.currentItem
                        }

                    }
                }

                ScrollView {
                    clip: true
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    ListView {
                        id: playlistView
                        model: playlistModel
                        delegate: dlg
                    }
                }
            }

        }

        SplitView {
            orientation: "Vertical"

            SplitView.preferredWidth: parent.width / 2


            ColumnLayout {

                SplitView.preferredHeight: parent.height / 2

                ToolBar {
                    Layout.fillWidth: true
                    RowLayout {
                        ToolButton {
                            icon.source: "images/add-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Adds the selected song to the playlist")
                            ToolTip.visible: hovered
                            enabled: songView.currentItem
                        }
                    }
                }

                ScrollView {
                    clip: true

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    ListView {
                        id: songView
                        model: songModel
                        delegate: dlg
                    }
                }

            }

            ColumnLayout {
                ToolBar {
                    Layout.fillWidth: true

                    RowLayout {
                        TextField {
                            id: playlistName
                        }

                        ToolButton {
                            icon.source: "images/save-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Save queue")
                            ToolTip.visible: hovered

                            enabled: playlistName.text && queueView.currentItem
                        }
                        ToolButton {
                            icon.source: "images/shuffle-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Shuffle queue")
                            ToolTip.visible: hovered
                        }
                        ToolButton {
                            icon.source: "images/clear-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Clears the queue")
                            ToolTip.visible: hovered
                        }
                        ToolButton {
                            icon.source: "images/remove-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Deletes the selected song from the playlist")
                            ToolTip.visible: hovered
                            enabled: queueView.currentItem
                        }

                        ToolButton {
                            icon.source: "images/arrow_upward-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Move the selected song up in the queue.")
                            ToolTip.visible: hovered
                            enabled: queueView.currentItem && queueView.currentIndex > 0
                        }
                        ToolButton {
                            icon.source: "images/arrow_downward-24px.svg"
                            hoverEnabled: true
                            ToolTip.text: qsTr("Move the selected song down in the down in the queue
    .")
                            ToolTip.visible: hovered
                            enabled: queueView.currentItem && queueView.currentIndex < queueModel.rowCount() - 1
                        }

                    }
                }

                ScrollView {
                    clip: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    ListView {
                        id: queueView
                        model: queueModel
                        delegate: dlg
                    }
                }
            }
        }
    }
}
