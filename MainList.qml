import QtQuick 2.9
import QtGraphicalEffects 1.0
import "VkFuncs.js" as VkFuncs

Rectangle {

    property var friendsList
    property int index
    property int current: 0
    property var currentUrl
    property var user_Id

    id: mainList
    color: '#553377'
    width: 350
    height: 600

    ListView {


        id: view
        clip: true
        anchors.topMargin: 2
        anchors.bottomMargin: 2
        anchors.fill: parent
        model: friendsList
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
                Image {
                    id: image

                    property bool rounded: true
                    property bool adapt: true
                    source: modelData['photo_medium']
                    layer.enabled: rounded
                    layer.effect: ShaderEffect {
                        property real adjustX: image.adapt ? Math.max(width / height, 1) : 1
                        property real adjustY: image.adapt ? Math.max(1 / (width / height), 1) : 1

                        fragmentShader: "
                        #ifdef GL_ES
                            precision lowp float;
                        #endif // GL_ES
                        varying highp vec2 qt_TexCoord0;
                        uniform highp float qt_Opacity;
                        uniform lowp sampler2D source;
                        uniform lowp float adjustX;
                        uniform lowp float adjustY;

                        void main(void) {
                            lowp float x, y;
                            x = (qt_TexCoord0.x - 0.5) * adjustX;
                            y = (qt_TexCoord0.y - 0.5) * adjustY;
                            float delta = adjustX != 1.0 ? fwidth(y) / 2.0 : fwidth(x) / 2.0;
                            gl_FragColor = texture2D(source, qt_TexCoord0).rgba
                                * step(x * x + y * y, 0.25)
                                * smoothstep((x * x + y * y) , 0.25 + delta, 0.25)
                                * qt_Opacity;
                        }"
                    }
                }

                Text {
                    id: user
                    color: "lightgrey"
                    font.bold: false
                    elide: Text.ElideRight
                    font.pixelSize: 20
                    renderType: Text.NativeRendering
                    text: "%1 %2".arg(modelData['first_name']).arg(modelData['last_name'])
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    user_Id = friendsList[mainList.current].id
                    view.currentIndex = model.index
                    lists.visible = false
                    usrDialog.visible = true
                    //editMessage.visible = true
                    //console.log("uId", friendsList[mainList.current].id)
                    VkFuncs.getMessages()
                }
            }
        }
        //currentIndex: mainList.current
        onCurrentIndexChanged: {
            mainList.current = currentIndex
            user_Id = friendsList[mainList.current].id
            console.debug("user_id:", user_Id)
        }
    }
}
