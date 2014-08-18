import QtQuick 1.1;import com.nokia.symbian 1.1
QueryDialog{
titleText:am.get(index).mif + " icon"
message:"<p><center>Do you really want to use "+am.get(index).mif+" icon?</center>"
acceptButtonText:"Yes"
rejectButtonText:"Cancel"
onAccepted:Helper.icon(am.get(index).mif);
Component.onCompleted:open()
onStatusChanged:if(status === DialogStatus.Closing)destroy()}
