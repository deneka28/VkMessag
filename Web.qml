import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtWebKit 3.0
import "VkFuncs.js" as VkFuncs

Item {

    property var friendsList

    id: web

    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight

    property alias webView: webView

    WebView {

        id: webView
        width: parent.width
        height: parent.height
        url: "https://oauth.vk.com/authorize?client_id=4494634&display=mobile&redirect_uri=https://oauth.vk.com/blank.html&scope=offline,messages,friends&response_type=token"
        onUrlChanged: {
            oauth.getToken(webView.url)
            if(oauth.accessToken.length !== 0)
            {
                web.visible = false
                VkFuncs.getUser()
                console.log("token", oauth.accessToken)
                lists.visible = true
            }
        }
    }
}
