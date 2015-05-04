import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    property alias button1: button1
    property alias button2: button2
    property alias button3: button3
    property alias button4: button4
    property alias button5: button5
    property alias button6: button6
    property alias button7: button7
    property alias button8: button8
    property alias button9: button9
    property alias button10: button10
    property alias button11: button11
    property alias button12: button12
    property alias button13: button13
    property alias button14: button14
    property alias button15: button15
    property alias button16: button16

    //property alias buttonLoop: buttonLoop

    GridLayout {
        id: gridLay
        anchors.centerIn: parent
        columns: 4
        Layout.fillHeight: true
        Layout.fillWidth: true

        Button {
            id: button1
            text: qsTr("1")
        }

        Button {
            id: button2
            text: qsTr("2")
        }

        Button {
            id: button3
            text: qsTr("3")
        }

        Button {
            id: button4
            text: qsTr("4")
        }

        Button {
            id: button5
            text: qsTr("5")
        }

        Button {
            id: button6
            text: qsTr("6")
        }

        Button {
            id: button7
            text: qsTr("7")
        }

        Button {
            id: button8
            text: qsTr("8")
        }

        Button {
            id: button9
            text: qsTr("9")
        }

        Button {
            id: button10
            text: qsTr("10")
        }

        Button {
            id: button11
            text: qsTr("11")
        }

        Button {
            id: button12
            text: qsTr("12")
        }

        Button {
            id: button13
            text: qsTr("13")
        }

        Button {
            id: button14
            text: qsTr("14")
        }

        Button {
            id: button15
            text: qsTr("15")
        }

        Button {
            id: button16
            text: qsTr("16")
        }

        //loop mode not fully functional - enable when it is
//        Button {
//            Layout.columnSpan: 4
//            Layout.fillWidth: true
//            id: buttonLoop
//            text: qsTr("Loop")
//            iconSource: "qrc:/loop.png"
//            checkable: true
//        }
    }

}
