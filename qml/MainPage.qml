import QtQuick 1.1
import com.nokia.symbian 1.1
Page {
id: mainPage
tools: ToolBarLayout {
ToolButton {
iconSource: "images/close.svg"
property Component __CloseDialog: null
onClicked:{
if (set_tool == false){
    Qt.quit();
}
if (!__CloseDialog) __CloseDialog = Qt.createComponent("CloseDialog.qml")
__CloseDialog.createObject(mainPage)}
}
ToolButton {
iconSource: "toolbar-settings"
onClicked: pageStack.push(Qt.resolvedUrl("settings.qml"))
}
ToolButton {
iconSource: "images/info.svg"
property Component __AboutDialog: null
onClicked:{ if (!__AboutDialog) __AboutDialog = Qt.createComponent("AboutDialog.qml")
    __AboutDialog.createObject(mainPage)}
}
}
Flickable {
anchors.fill: parent
contentHeight: channels.height
Column {
id: channels
spacing: 0
ListItem {
onClicked: {
Helper.launch()
}
ListItemText {
role: "Title"
text: qsTr("Launch WhatsApp")
anchors.centerIn: parent
}
}
ListItem {
onClicked: {
Helper.close2()
}
ListItemText {
role: "Title"
text: qsTr("Close WhatsApp")
anchors.centerIn: parent
}
}
ListItem {
onClicked: {
Helper.close()
Helper.reset()
Helper.hide()
}
ListItemText {
role: "Title"
text: qsTr("Hide Homescreen popup")
anchors.centerIn: parent
}
}
ListItem {
onClicked: {
Helper.close()
Helper.reset()
Helper.resetNote()
}
ListItemText {
role: "Title"
text: qsTr("Show Homescreen popup")
anchors.centerIn: parent
}
}
ListItem {
onClicked: {
    pageStack.push(Qt.resolvedUrl("icons.qml"));
    Helper.note()
}
ListItemText {
role: "Title"
text: "Change Icons"
anchors.centerIn: parent
}
}
Label {
text: "\nWhatsApp Modifier\ncreated by huellif"
anchors.horizontalCenter: parent.horizontalCenter
}
}
}
}

