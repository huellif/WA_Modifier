import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
id: removeDialog
property bool __isClosing:false
titleText:"Remove Dialog"
privateCloseIcon:true
message:"<p><center>Do really want to remove your current icon?</p>"
acceptButtonText:"Remove"
rejectButtonText:"Cancel"
onAccepted: Helper.del()
onRejected: removeDialog.destroy()
Component.onCompleted: open()
onStatusChanged: {
if (status === DialogStatus.Closing) __isClosing = true
else if (status === DialogStatus.Closed && __isClosing) removeDialog.destroy()}}
