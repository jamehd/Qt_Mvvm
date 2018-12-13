import QtQuick 2.0
import QtQuick.Controls 1.5
import ENUMS 1.0

Rectangle {
    id: rectangle
    width: 800
    height: 80
    color: "#b3e3c0"

    Button {
        id: idBtnBack
        width: 80
        height: 80
        text: qsTr("BACK")
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        clip: false
        onClicked: TRANSITION_SCREEN.backScene()
    }

    Label {
        id: idLabelStatusBar
        x: 382
        y: 32
        width: 100
        height: 30
        text: qsTr("StatusBar")
        textFormat: Text.AutoText
        renderType: Text.NativeRendering
        fontSizeMode: Text.FixedSize
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Button {
        id: idBtnSceneA
        x: 0
        y: 2
        width: 80
        height: 80
        text: qsTr("Scene_A")
        anchors.topMargin: 0
        anchors.leftMargin: 91
        anchors.left: parent.left
        anchors.top: parent.top
        clip: false
        onClicked: {
            TRANSITION_SCREEN.showScene(ENUMS.SCENE_A)
        }
    }

    Button {
        id: idBtnSceneB
        x: 3
        y: 5
        width: 80
        height: 80
        text: qsTr("Scene_B")
        anchors.topMargin: 0
        anchors.leftMargin: 193
        anchors.left: parent.left
        anchors.top: parent.top
        clip: false
        onClicked: {
            TRANSITION_SCREEN.showScene(ENUMS.SCENE_B)
        }
    }

}
