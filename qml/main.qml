import QtQuick 1.1;import com.nokia.symbian 1.1;import "settings.js" as Setting
PageStackWindow {
property bool set_tool:Setting.get("tool") != '' ? Setting.get("tool") : true;
property bool set_tool2:Setting.get("tool2") != '' ? Setting.get("tool2") : true;
initialPage:MainPage {id:mainPage}
showStatusBar:set_tool2
QtObject{
id:dialog
property Component c:null
function create (qmlfile){c = Qt.createComponent(qmlfile);
c.createObject(mainPage)}}}
