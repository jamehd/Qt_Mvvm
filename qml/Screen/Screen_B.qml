import QtQuick 2.0
import QtQuick.Controls 1.5
import ENUMS 1.0

Rectangle {
    id: rectangle
    width: 800
    height: 370
    color: "#52f248"

    Label {
        id: label
        x: 295
        width: 210
        height: 74
        text: qsTr("SCENE_B")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 0
    }

}
