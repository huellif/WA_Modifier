import QtQuick 1.1
import com.nokia.symbian 1.1
Page {
id: rectangle1
tools: ToolBarLayout {
ToolButton {
iconSource: "images/back.svg"
onClicked: pageStack.pop();
}
ToolButton {
iconSource: "images/delete.svg"
property Component __RemoveDialog: null
onClicked:{ if (!__RemoveDialog) __RemoveDialog = Qt.createComponent("RemoveDialog.qml")
__RemoveDialog.createObject(mainPage)}
}
ToolButton {
iconSource: "images/refresh.svg"
property Component __RebootDialog: null
onClicked:{ if (!__RebootDialog) __RebootDialog = Qt.createComponent("RebootDialog.qml")
__RebootDialog.createObject(mainPage)}
}
}
ListModel {
id: appModel
ListElement { icon: "pics/0.svg"; mif: "Default"}
ListElement { icon: "pics/1.svg"; mif: "Transparent" }
ListElement { icon: "pics/2.svg"; mif: "NewStyle" }
ListElement { icon: "pics/3.svg"; mif: "BlueStyle" }
ListElement { icon: "pics/4.svg"; mif: "Weed" }
ListElement { icon: "pics/5.svg"; mif: "BlackBerry" }
ListElement { icon: "pics/6.svg"; mif: "BelleXdefault" }
ListElement { icon: "pics/7.svg"; mif: "BelleXred" }
ListElement { icon: "pics/8.svg"; mif: "BelleXgreen"}
ListElement { icon: "pics/9.svg"; mif: "BelleXwhite" }
ListElement { icon: "pics/10.svg"; mif: "BelleXblue" }
ListElement { icon: "pics/11.svg"; mif: "BelleXblack" }
ListElement { icon: "pics/12.svg"; mif: "DefaultViral" }
ListElement { icon: "pics/13.svg"; mif: "TransViral" }
ListElement { icon: "pics/14.svg"; mif: "GreenViral" }
ListElement { icon: "pics/15.svg"; mif: "GreenViral" }
ListElement { icon: "pics/16.svg"; mif: "GoldViral" }
ListElement { icon: "pics/17.svg"; mif: "BlueViral" }
ListElement { icon: "pics/18.svg"; mif: "ChocViral" }
ListElement { icon: "pics/19.svg"; mif: "PurpleViral" }
ListElement { icon: "pics/20.svg"; mif: "MagentaViral" }
ListElement { icon: "pics/21.svg"; mif: "BlackViral" }
ListElement { icon: "pics/22.svg"; mif: "RedViral" }
}
CoverFlow {
id: coverflow1
listModel: appModel
width: parent.width
anchors.top: parent.top
anchors.bottom: rectangle1.bottom
color: "black"
}
}
