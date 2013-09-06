import QtQuick 1.1
import com.nokia.symbian 1.1
QueryDialog{
id: rebootDialog
property bool __isClosing: false
titleText: qsTr("Reboot Dialog")
privateCloseIcon: true
message: qsTr("<p><center>Do really want to Reboot your Phone?</p>")
acceptButtonText: qsTr("Reboot")
rejectButtonText : qsTr("Cancel")
onAccepted: Helper.reboot()
onRejected: rebootDialog.destroy()
Component.onCompleted: open()
onStatusChanged: {
        if (status === DialogStatus.Closing) __isClosing = true
        else if (status === DialogStatus.Closed && __isClosing) rebootDialog.destroy()
    }
}
