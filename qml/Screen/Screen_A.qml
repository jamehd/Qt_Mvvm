import QtQuick 2.0
import QtQuick.Controls 1.5
import ENUMS 1.0

Rectangle {
    id: rectangle
    width: 800
    height: 370
    color: "#eb6262"

    Label {
        id: label
        x: 295
        width: 211
        height: 46
        color: "#efebeb"
        text: qsTr("SCENCE_A")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }


}
