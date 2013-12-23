import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
titleText:"Close Dialog"
privateCloseIcon:true
message:"<p><center>Do you really want to close WhatsApp Modifier?</center>"
acceptButtonText:"Close"
rejectButtonText:"Cancel"
onAccepted:Qt.quit()
onRejected:destroy()
Component.onCompleted:open()
onStatusChanged: if (status === DialogStatus.Closing) destroy()}
