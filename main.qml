import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Quick Sound Board")
    width: 400
    height: 200
    visible: true

    MainForm {
        id: mainF
        anchors.fill: parent
        button1.onClicked: soundplayer.startSample(1)
        button2.onClicked: soundplayer.startSample(2)
        button3.onClicked: soundplayer.startSample(3)
        button4.onClicked: soundplayer.startSample(4)
        button5.onClicked: soundplayer.startSample(5)
        button6.onClicked: soundplayer.startSample(6)
        button7.onClicked: soundplayer.startSample(7)
        button8.onClicked: soundplayer.startSample(8)
        button9.onClicked: soundplayer.startSample(9)
        button10.onClicked: soundplayer.startSample(10)
        button11.onClicked: soundplayer.startSample(11)
        button12.onClicked: soundplayer.startSample(12)
        button13.onClicked: soundplayer.startSample(13)
        button14.onClicked: soundplayer.startSample(14)
        button15.onClicked: soundplayer.startSample(15)
        button16.onClicked: soundplayer.startSample(16)
        //buttonLoop.onClicked: soundplayer.toggleLoop()
    }

    Connections {
        target: soundplayer
        onDeactivateButton: {
            if(number > 0 && number < 17)
            {
                mainF["button" + number].enabled = false;
            }
        }

        onButtonPlaying: {
            if(playing)
            {
                mainF["button" + number].iconSource = "qrc:/play.png";
            }
            else
            {
                mainF["button" + number].iconSource = "";
            }
        }

        onButtonSetText: {
            mainF["button" + number].text = text;
        }
    }
}
