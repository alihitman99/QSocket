import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
// import Notif 1.0

Window {
    width: Screen.width / 2
    height: 600
    visible: true
    title: client.clientName
    x: Screen.width / 2
    color: "#5D5D5D"

    // TextArea {
    //     id: chatBox
    //     readOnly: true
    //     wrapMode: TextArea.Wrap
    //     height: 300
    // }

    ListView {
        id: chatListView
        model: chatModel
        clip: true
        anchors.fill: parent

        delegate: Item {
            width: chatListView.width
            height: bubble.implicitHeight + 10

            Rectangle {
                id: bubble
                radius: 10
                color: isClient ? "#d4ffd4" : "#e0e0ff"

                anchors.margins: 10
                anchors.right: isClient ? parent.right : undefined
                anchors.left: isClient ? undefined : parent.left

                Text {
                    id: txt
                    text: msgRole
                    padding: 8
                    wrapMode: Text.Wrap
                }

                implicitWidth: Math.min(txt.implicitWidth + 20, chatListView.width * 0.75)
                implicitHeight: txt.implicitHeight + 10
            }
        }
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
                // client.sendMessage(textField.text)
                // chatBox.text += "Me: " + textField.text + "\n"
                chatModel.addItem(textField.text, true)
                chatListView.positionViewAtEnd()

            }
        }
    }

    Connections {
        target: client
        function onMessageReceived(msg) {
            chatModel.addMessage(msg, false)
            chatListView.positionViewAtEnd()
        }
    }

    // Connections{
    //     target: client
    //     function onMessageReceived(msg) {
    //         chatBox.text += msg + "\n"
    //     }
    // }
}
