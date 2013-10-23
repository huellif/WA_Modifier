import QtQuick 1.1
Rectangle {
id: coverFlow
property int itemWidth: 150
property int itemHeight: 150
property ListModel listModel
signal indexChanged(int index)
Component {
id: appDelegate
Flipable {
id: myFlipable
property bool flipped: false
width: itemWidth; height: itemHeight
z: PathView.z
scale: PathView.iconScale
MouseArea {
anchors.fill: parent
property Component __Dialog: null
onClicked:{ if (!__Dialog) __Dialog = Qt.createComponent("Dialog.qml")
__Dialog.createObject(mainPage)}
}
front:
Image {
height:itemHeight
width:itemWidth
anchors.centerIn:parent
source:icon
smooth:true}}}
PathView {
id: myPathView
anchors.fill: parent
preferredHighlightBegin: 0.5
preferredHighlightEnd: 0.5
focus: true
interactive: true
model: listModel
delegate: appDelegate
path: Path{
startX: 0
startY: coverFlow.height / 2
PathAttribute { name: "z"; value: 0 }
PathAttribute { name: "iconScale"; value: 0.2 }
PathLine { x: coverFlow.width / 2; y: coverFlow.height / 2;  }
PathAttribute { name: "z"; value: 100 }
PathAttribute { name: "angle"; value: 0 }
PathAttribute { name: "iconScale"; value: 1.0 }
PathLine { x: coverFlow.width; y: coverFlow.height / 2; }
PathAttribute { name: "z"; value: 0 }
PathAttribute { name: "iconScale"; value: 0.2 }}}
Component.onCompleted: {
myPathView.currentIndexChanged.connect(function(){
indexChanged(myPathView.currentIndex)})}}
