import QtQuick 2.0
import QtQuick.Controls 2.12

Component {
    ItemDelegate {
        Text {
            text: value
        }
        width: parent.width

        highlighted: ListView.isCurrentItem

        onClicked: {
            ListView.view.currentIndex = index
        }
    }
}