import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import Httprequest 1.0
import Ftprequest 1.0
ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true
    Login
    {
        id:loginer;
        visible: false;
        MouseArea
        {
            anchors.fill: parent;
            onClicked:
            {
                console.log("startRequest");
                httprequest.startRequest();
            }
        }
    }
    Regist
    {
        id:register;
        visible: false;
    }
    Httprequest{id:httprequest;}
    Ftprequest{id:ftprequest;}
    Component.onCompleted: loginer.visible=true;
}
