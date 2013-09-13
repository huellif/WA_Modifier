import QtQuick 1.1
import com.nokia.symbian 1.1
import "settings.js" as Setting
PageStackWindow {
property bool set_tool : Setting.get("tool") != '' ? Setting.get("tool") : true;
id: window
initialPage: MainPage { id: mainPage }
showStatusBar: true
showToolBar: true
}
