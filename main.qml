import QtQuick 2.9
import QtQuick.Window 2.3
import "VkFuncs.js" as VkFuncs

Window {

    id: root
    visible: true
    width: 350
    height: 600
    title: qsTr("Vk messandger")

    property var friendsList: webStart.friendsList


    Web {
        id: webStart
        visible: true
    }

    MainList {
        id: lists
        visible: false
        friendsList: root.friendsList
    }
}
