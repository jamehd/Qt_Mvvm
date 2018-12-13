import QtQuick 2.6
import "./StatusBar"
import "./Screen"
import QtQml.Models 2.1
Item {
    visible: true
    width: 800
    height: 450

    StatusBar {
        id: idStatusBar
        anchors.top: parent.top
        anchors.left: parent.left
    }

    property var layer_BG: layer_base_1
    function switchLayerBase(gotoBG, gotoFG) {
        console.log("Transition: switchLayerBase");
        if ( gotoFG.item !== null ) {
            console.log("Transition: gotoFG:", gotoFG.objectName);
            gotoFG.item.visible = true
            gotoFG.z = 1
        }
        if ( gotoBG.item !== null ) {
            console.log("Transition: gotoBG:", gotoBG.objectName);
            gotoBG.item.visible = false
            gotoBG.z = -1
            gotoBG.sourceComponent = null
            TRANSITION_SCREEN.hideScene(gotoBG.scene_ID)
        }
        layer_BG = gotoBG;
    }
    Connections {
        target: TRANSITION_SCREEN
        onChangeScene: {
            console.log("Transition: onChangeScene - layer_BG:", layer_BG.objectName);
            layer_BG.source = ""
            layer_BG.scene_ID = scene_ID
            layer_BG.source = pathScene
        }
    }
    Loader {
        id: layer_base_1
        objectName: "layer_base_1"
        property int scene_ID: 0
        anchors.top: idStatusBar.bottom
        anchors.left: parent.left
        onLoaded: switchLayerBase( layer_base_2, layer_base_1 )
    }
    Loader {
        id: layer_base_2
        objectName: "layer_base_2"
        property int scene_ID: 0
        anchors.top: idStatusBar.bottom
        anchors.left: parent.left
        onLoaded: switchLayerBase( layer_base_1, layer_base_2 )
    }
}
