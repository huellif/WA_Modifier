import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
id: aboutDialog
icon: "images/note_info.svg"
titleText: "About"
message: "WhatsApp Modifier v1.6.0\ncreated by Fabian\n\nthanks Abdoul, Viral, Shailja, hqnqvn, IFA for your icons\n\nThanks Paul for your help with QtQuick\n\nspecial thanks to Oleg and Teoman\n\nThanks Valentin for the idea with icon cache :)"
acceptButtonText: qsTr("Back")
onAccepted: aboutDialog.destroy()
Component.onCompleted:open()}
