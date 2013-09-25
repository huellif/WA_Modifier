import QtQuick 1.1
import com.nokia.symbian 1.1
QueryDialog{
id: aboutDialog
icon: "images/note_info.svg"
titleText: qsTr("About")
message: qsTr("WhatsApp Modifier v1.4\ncreated by Fabian\n\nthanks Abdoul, Viral, Shailja, hqnqvn for your icons\n\nThanks Paul for your help with QtQuick\n\nspecial thanks to Oleg and Teoman")
acceptButtonText: qsTr("Back")
onAccepted: aboutDialog.destroy()
Component.onCompleted:open()
}
