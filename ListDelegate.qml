import QtQuick 2.0

Component {

    // Copy and paste from here
    // https://doc.qt.io/qt-5/qtquick-tutorials-dynamicview-dynamicview2-example.html

    id: dragDelegate

    MouseArea {
        id: dragArea

        property bool held: false

        anchors { left: parent.left; right: parent.right }
        height: content.height

        drag.target: held ? content : undefined
        drag.axis: Drag.YAxis

        onPressAndHold: held = true
        onReleased: held = false

        Rectangle {
            id: content
            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }
            width: dragArea.width; height: column.implicitHeight + 4

            border.width: 1
            border.color: "lightsteelblue"
            color: dragArea.held ? "lightsteelblue" : "white"
            Behavior on color { ColorAnimation { duration: 100 } }
            radius: 2
            states: State {
                when: dragArea.held

                ParentChange { target: content; parent: root }
                AnchorChanges {
                    target: content
                    anchors { horizontalCenter: undefined; verticalCenter: undefined }
                }
            }
            Column {
                id: column
                anchors { fill: parent; margins: 2 }

                Text { text: value }
            }
        }
    }
}
