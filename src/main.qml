import QtQuick 2.12
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
import QTunes 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 800
    height: 480
    title: qsTr("QTunes")

    ListDelegate {
        id: dlg
    }

    header: ToolBar {
        enabled: controller.connectionState === Controller.Connected

        ColumnLayout {
            anchors.fill: parent

            RowLayout {
                Layout.fillWidth: true

                ToolButton {
                    id: playButton
                    icon.source: "images/play_arrow-24px.svg"
                    hoverEnabled: true
                    ToolTip.text: qsTr("Play")
                    ToolTip.visible: hovered

                    onClicked: {
                        controller.handleBtnClick()
                    }

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
        visible: controller.connectionState !== Controller.Connected
        modal: false
        interactive: false
        Rectangle {
            anchors.fill: parent;

            ColumnLayout {
                id: connectionColumn
                anchors.fill: parent
                opacity: 1

                RowLayout {
                    id: connectRow
                    width: 100
                    height: 100


                    Button {
                        id: connectButton
                        text: qsTr("Connect")
                        enabled: controller.connectionState === Controller.Disconnected

                        onClicked: {
                            controller.connectToMPD()
                        }
                    }

                    BusyIndicator {
                        id: connectBusy
                        visible: controller.connectionState === Controller.Connecting;
                    }
                }

                Label {
                    Layout.fillWidth: true
                    text: controller.connectionError
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

                    ListView {
                        anchors.fill: parent
                        model: artistModel
                        delegate: dlg
                        enabled: controller.connectionState === Controller.Connected
                        clip: true
                        headerPositioning: ListView.OverlayHeader
                        ScrollBar.vertical: ScrollBar {}

                        onCurrentItemChanged: {
                            console.log(dbView.currentIndex)
                        }

                        interactive: true

                        header: ToolBar {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            z: 2
                            RowLayout {
                                ComboBox {
                                    model: ListModel {
                                        ListElement {
                                            text: "artist"
                                        }
                                        ListElement {
                                            text: "albumartist"
                                        }
                                        ListElement {
                                            text: "composer"
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                Item {
                    SplitView.preferredWidth: dbView.width / 3

                    ListView {
                        anchors.fill: parent

                        model: albumModel
                        delegate: dlg

                        enabled: controller.connectionState === Controller.Connected

                        clip: true
                        headerPositioning: ListView.OverlayHeader
                        ScrollBar.vertical: ScrollBar {}

                        header: ToolBar {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            z: 2
                        }
                    }
                }

                Item {
                    ListView {
                        anchors.fill: parent
                        model: songModel
                        delegate: dlg
                        enabled: controller.connectionState === Controller.Connected
                        clip: true
                        headerPositioning: ListView.OverlayHeader
                        ScrollBar.vertical: ScrollBar {}

                        header: ToolBar {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            z: 2
                            RowLayout {
                                ToolButton {
                                    id: addButton
                                    icon.source: "images/add-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Adds the selected song to the playlist")
                                    ToolTip.visible: hovered
                                }

                                ToolButton {
                                    id: playSelectedButton
                                    icon.source: "images/play_arrow-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Play the selected song")
                                    ToolTip.visible: hovered
                                }
                            }
                        }
                    }
                }
            }
        }

        Item {

            SplitView {
                anchors.fill: parent
                Item {
                    SplitView.preferredWidth: dbView.width / 3

                    ListView {
                        anchors.fill: parent
                        model: playlistModel
                        delegate: dlg
                        enabled: controller.connectionState === Controller.Connected

                        clip: true
                        headerPositioning: ListView.OverlayHeader
                        ScrollBar.vertical: ScrollBar {}

                        header: ToolBar {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            z: 2

                            RowLayout {
                                ToolButton {
                                    id: rmButton
                                    icon.source: "images/delete-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Remove selected playlist")
                                    ToolTip.visible: hovered
                                }

                                ToolButton {
                                    id: renameButton
                                    icon.source: "images/edit-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Rename selected playlist")
                                    ToolTip.visible: hovered
                                }
                            }
                        }

                    }

                }

                Item {

                    ListView {
                        anchors.fill: parent
                        model: queueModel
                        delegate: dlg
                        enabled: controller.connectionState === Controller.Connected
                        clip: true
                        ScrollBar.vertical: ScrollBar {}
                        headerPositioning: ListView.OverlayHeader

                        header:
                            ToolBar {
                            anchors.left: parent.left
                            anchors.right: parent.right

                            // https://stackoverflow.com/a/39383505/240515
                            z: 2

                            RowLayout {
                                ToolButton {
                                    id: saveButton
                                    icon.source: "images/save-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Save queue")
                                    ToolTip.visible: hovered
                                }
                                ToolButton {
                                    id: shuffleButton
                                    icon.source: "images/shuffle-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Shuffle queue")
                                    ToolTip.visible: hovered
                                }
                                ToolButton {
                                    id: clearButton
                                    icon.source: "images/clear-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Clears the queue")
                                    ToolTip.visible: hovered
                                }
                                ToolButton {
                                    id: removeButton
                                    icon.source: "images/remove-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Deletes the selected song from the playlist")
                                    ToolTip.visible: hovered
                                }

                                ToolButton {
                                    id: bubbleUpButton
                                    icon.source: "images/arrow_upward-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Move the selected song up in the queue.")
                                    ToolTip.visible: hovered
                                }
                                ToolButton {
                                    id: bubbleDownButton
                                    icon.source: "images/arrow_downward-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Move the selected song down in the down in the queue
.")
                                    ToolTip.visible: hovered
                                }

                                ToolButton {
                                    id: playQueuedButton
                                    icon.source: "images/play_arrow-24px.svg"
                                    hoverEnabled: true
                                    ToolTip.text: qsTr("Play the selected queued song")
                                    ToolTip.visible: hovered
                                }
                            }

                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        controller.connectToMPD()
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:55;anchors_y:26}
}
##^##*/
