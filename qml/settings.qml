import QtQuick 1.1
import com.nokia.symbian 1.1
import "settings.js" as Setting
Page {
tools: ToolBarLayout {
ToolButton {
iconSource: "toolbar-back"
onClicked: pageStack.pop();
}
}
Flickable {
anchors.fill: parent
Column {
ListHeading {
ListItemText {
anchors.centerIn: parent
role: "Heading"
text: "Settings"
}
}
ListItem {
enabled: false
ListItemText {
role: "Title"
text: "Show close Dialog"
anchors.verticalCenter: parent.verticalCenter
}
Switch {
anchors.verticalCenter: parent.verticalCenter
anchors.right: parent.right
checked: set_tool
onClicked: {
set_tool = checked;
Setting.set("tool",checked)
}
}
}
}
}
}
