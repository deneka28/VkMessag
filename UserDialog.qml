import QtQuick 2.9
import QtGraphicalEffects 1.0
import "VkFuncs.js" as VkFuncs

Rectangle {

    property var messageHistory
//    property int index
//    property int current: 0
//    property var currentUrl
//    property var user_Id

    id: userDialog
    color: '#553377'
    width: 350
    height: 600

    ListView {


        id: view
        clip: true
        anchors.topMargin: 2
        anchors.bottomMargin: 2
        anchors.fill: parent
        model: messageHistory
        spacing: 2

        delegate: Rectangle {

            property var isCurrent: ListView.isCurrentItem

            width: view.width
            height: 110
            anchors.horizontalCenter: parent.horizontalCenter
            color: '#ffffff'
            radius: 4
            border {
                color: 'lightgray'
                width: 1
            }
            Row {
                anchors.margins: 5
                anchors.fill: parent
                spacing: 5

            }

        }

    }
}
