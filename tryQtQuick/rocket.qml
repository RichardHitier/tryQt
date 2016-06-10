import QtQuick 2.0

Rectangle {
    id: root
    width: 500; height: 400
    Image {
        id: rocketImg
        source: "assets/rocket.png"
        x: (parent.width - width)/2;
        y: (parent.height-height)/2;
        width: parent.width/10
        height: parent.height/20
    }
    Text {
        id: titleText
        text: qsTr("text")
        y: rocketImg.y+rocketImg.height+10
        x: rocketImg.x
    }

}
