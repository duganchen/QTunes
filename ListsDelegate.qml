import QtQuick 2.0

Component {
    id: listsDelegate
    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        height: txt.contentHeight

        Text {
            id: txt
            text: value
        }
    }

}
