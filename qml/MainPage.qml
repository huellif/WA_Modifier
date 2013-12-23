import QtQuick 1.1
import com.nokia.symbian 1.1
Page{
id:mainPage
tools:ToolBarLayout{
ToolButton{
iconSource: "images/close.svg"
onClicked:{
if (set_tool == false) Qt.quit();
dialog.create("CloseDialog.qml")}}
ToolButton{
iconSource:"toolbar-settings"
onClicked:pageStack.push(Qt.resolvedUrl("settings.qml"))}
ToolButton{
iconSource:"images/info.svg"
onClicked:dialog.create("AboutDialog.qml")}}
Flickable{
anchors.fill:parent
contentHeight:c.height
Column{
id:c
ListItem{
onClicked:{
Helper.launch()}
ListItemText{
role:"Title"
text:"Launch WhatsApp"
anchors.centerIn:parent}}
ListItem{
onClicked:{
Helper.close(false)}
ListItemText{
role:"Title"
text:"Close WhatsApp"
anchors.centerIn: parent}}
ListItem{
onClicked:Helper.hide()
ListItemText{
role:"Title"
text:"Hide homescreen popup"
anchors.centerIn: parent}}
ListItem{
onClicked: Helper.resetNote()
ListItemText{
role:"Title"
text:"Show homescreen popup"
anchors.centerIn: parent}}
ListItem{
onClicked:{
pageStack.push(Qt.resolvedUrl("icons.qml"));
Helper.note()}
ListItemText{
role:"Title"
text:"Change icons"
anchors.centerIn: parent}}
Label{
text:"\nWhatsApp Modifier\ncreated by huellif"
anchors.horizontalCenter: parent.horizontalCenter}}}}
