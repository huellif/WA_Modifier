import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
titleText:"Reboot/Clear Dialog"
privateCloseIcon:true
message:"<p><center>Do really want to clear icon cache or reboot?</p>"
acceptButtonText:"Clear"
rejectButtonText:"Reboot"
onAccepted:Helper.clear()
onRejected:Helper.reboot()
Component.onCompleted:open()
onStatusChanged:if(status === DialogStatus.Closing)destroy()}
