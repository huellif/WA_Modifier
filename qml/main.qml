import QtQuick 1.1;import com.nokia.symbian 1.1;import "settings.js" as Setting
PageStackWindow {
property bool set_tool : Setting.get("tool") != '' ? Setting.get("tool") : true;
property bool set_tool2 : Setting.get("tool2") != '' ? Setting.get("tool2") : true;
id: window
initialPage: MainPage { id: mainPage }
showStatusBar: set_tool2
showToolBar: true
QtObject{
id:dialog
property Component __comp: null
function create (qmlfile){ __comp = Qt.createComponent(qmlfile)
__comp.createObject(mainPage)}}}
