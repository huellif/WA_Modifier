import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
icon:"images/note_info.svg"
titleText:"About"
message: "WhatsApp Modifier v1.7.0b\ncreated by Fabian\n\nthanks Abdoul, Viral, Shailja, hqnqvn, IFA for your icons\n\nThanks Paul and Motaz for your help with QtQuick\n\nspecial thanks to Oleg and Teoman\n\nThanks Valentin for the idea with icon cache :)"
acceptButtonText:qsTr("Back")
onAccepted:destroy()
Component.onCompleted:open()}
