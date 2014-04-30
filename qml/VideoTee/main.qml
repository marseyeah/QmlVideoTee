import QtQuick 2.0
import QtMultimedia 5.0
import MyComponents 1.0

Rectangle {
    width: 800
    height: 480
    color: "black"

    MediaPlayer {
        id: player
        autoPlay: true
        source: "http://download.blender.org/durian/trailer/sintel_trailer-480p.mp4"
    }

    VideoTee {
        id: tee
        source: player
    }

    Row {
        anchors.centerIn: parent
        spacing: 50

        VideoOutput {
            id: output1
            width: 300
            height: 200
            source: tee
        }

        VideoOutput {
            id: output2
            width: 300
            height: 200
            source: tee
        }
    }
}
