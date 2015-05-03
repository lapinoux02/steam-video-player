import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias button3: button3
    property alias button2: button2
    property alias button1: button1

    RowLayout {
        id: rowLayout1
        anchors.centerIn: parent

        Button {
            id: button1
            text: qsTr("Press Me 1")
            activeFocusOnPress: false
            isDefault: false
            enabled: true
        }

        Button {
            id: button2
            text: qsTr("Press Me 2")
        }

        Button {
            id: button3
            text: qsTr("Press Me 3")
            tooltip: ""
        }
    }

    Button {
        id: button4
        x: 80
        y: 380
        text: qsTr("Button")
    }
}
