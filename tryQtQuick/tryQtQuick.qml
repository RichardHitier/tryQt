import QtQuick 2.3

Rectangle {
    width: 360
    height: 360
    id: root
    Text {
        anchors.centerIn: parent
        text: "Hello World"
    }
    Rectangle {
        width: 60
        height: 60
        color: '#7766bb'
        anchors.centerIn: root
        Text {
            id: name
            text: qsTr("text")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.quit();
            }
        }
    }
}

