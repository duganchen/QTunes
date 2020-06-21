import QtQuick 2.0
import QtQuick.Controls 2.12

Component {
    ItemDelegate {
        Text {
            text: value
        }

        // parent seems to be null once it's scrolled off.
        width: parent ? parent.width : 0

        highlighted: ListView.isCurrentItem

        onClicked: {
            ListView.view.currentIndex = index
        }
    }
}
