import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
// import Notif 1.0

Window {
    width: Screen.width / 2
    height: 600
    visible: true
    title: qsTr("Client Window")
    x: Screen.width / 2
    y: 20
    color: "#5D5D5D"

    TextArea {
        id: chatBox
        readOnly: true
        wrapMode: TextArea.Wrap
        height: 300
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
                client.sendMessage(textField.text)
            }
        }
    }

    Connections{
        target: client
        function onMessageReceived(msg) {
            chatBox.text += msg + "\n"
        }
    }
}
