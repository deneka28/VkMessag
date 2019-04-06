import QtQuick 2.9
import QtQuick.Window 2.3
import "VkFuncs.js" as VkFuncs

Window {

    property var friendsList: webStart.friendsList
   // property var user_Id: lists.user_Id
    property var messageHistory: usrDialog.messageHistory

    id: root
    visible: true
    width: 350
    height: 600
    title: qsTr("Vk messandger")




    Web {
        id: webStart
        visible: true
    }

    MainList {
        id: lists
        visible: false
        friendsList: root.friendsList
        //user_Id: root.user_Id
    }

    UserDialog {
        id: usrDialog
        visible: false
        messageHistory: root.messageHistory

    }
}
