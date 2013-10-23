import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
id: root
property bool __isClosing: false
titleText:"Close Dialog"
privateCloseIcon:true
message: "<p><center>Do you really want to close WhatsApp Modifier?</center>"
acceptButtonText:"Close"
rejectButtonText :"Cancel"
onAccepted: Qt.quit()
onRejected: root.destroy()
Component.onCompleted: open()
onStatusChanged: {
if (status === DialogStatus.Closing) __isClosing = true
else if (status === DialogStatus.Closed && __isClosing) root.destroy()}}
