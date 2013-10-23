import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
id: root
privateCloseIcon:true
property bool __isClosing:false
titleText:appModel.get(index).mif + " icon"
message:"<p><center>Do you really want to use " + appModel.get(index).mif + " icon?</center>"
acceptButtonText:"Yes"
rejectButtonText:"Cancel"
onAccepted: Helper.icon(appModel.get(index).mif);
Component.onCompleted: open()
onStatusChanged: {
if (status === DialogStatus.Closing) __isClosing = true
else if (status === DialogStatus.Closed && __isClosing) root.destroy()}}
