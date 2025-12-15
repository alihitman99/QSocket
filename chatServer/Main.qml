import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
// import Notif 1.0

Window {
    width: Screen.width / 2
    height: 600
    visible: true
    title: qsTr("Server Window")
    x: 0
    color: "#5D5D5D"

    TextArea {
        id: listText
        readOnly: true
    }

    RowLayout{
        anchors.bottom: parent.bottom
        spacing: 5
        TextField{
            id: textField
            placeholderText: "Enter a text"
        }
        Button{
            text: "➤"
            onClicked: {
                server.sendToAll(textField.text)
                listText.text += "Me: " + textField.text + "\n"
            }
        }
    }

    Connections{
        target: server
        function onMessageReceived(msg) {
            listText.text += msg + "\n"
        }
    }

}
