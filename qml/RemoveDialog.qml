import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
titleText:"Remove Dialog"
privateCloseIcon:true
message:"<p><center>Do really want to remove your current icon?</p>"
acceptButtonText:"Remove"
rejectButtonText:"Cancel"
onAccepted:Helper.del()
Component.onCompleted:open()
onStatusChanged:if(status === DialogStatus.Closing)destroy()}
