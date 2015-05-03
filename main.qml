/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0

Rectangle {
    id: root
    anchors.fill: parent
    color: "black"

    property string source1
    property string source2
    property color bgColor: "black"
    property real volume: 0.25
    property bool perfMonitorsLogging: false
    property bool perfMonitorsVisible: false

    QtObject {
        id: d
        property int itemHeight: root.height > root.width ? root.width / 10 : root.height / 10
        property int buttonHeight: 0.8 * itemHeight
        property int margins: 5
    }

    Rectangle {
        id: inner
        anchors.fill: parent
        color: root.bgColor

        Button {
            id: openFile1Button
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
            }
            bgColor: "#212121"
            bgColorSelected: "#757575"
            textColorSelected: "white"
            height: d.buttonHeight
            text: (root.source1 == "") ? "Select file 1" : root.source1
            enabled: false
        }

        Rectangle {
            id: divider
            height: 1
            width: parent.width
            color: "black"
            anchors.top: openFile1Button.bottom
        }

        Rectangle {
            id: sceneSelectionPanel
            //property int itemHeight: 25
            property string sceneSource: ""
            objectName: "sceneSelectionPanel"
            color: "#212121"
            anchors {
                top: divider.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }
            radius: 0
            onSceneSourceChanged: {
                sceneLoader.source = sceneSource
                var scene = null
                var innerVisible = true
                if (! sceneSource == "")
                {
                    scene = sceneLoader.item
                    if (scene) {
                        if (scene.contentType === "video" && source1 === "") {
                            //errorDialog.show("You must first select a video file")
                            sceneSource = ""
                        } else {
                            scene.parent = root
                            scene.color = root.bgColor
                            scene.buttonHeight = d.buttonHeight
                            scene.source1 = source1
                            scene.source2 = source2
                            scene.volume = volume
                            scene.anchors.fill = root
                            scene.close.connect(closeScene)
                            scene.content.initialize()
                            innerVisible = false
                        }
                    }
                }
                else
                {
                    closeScene()
                }

                videoFramePaintedConnection.target = scene
                inner.visible = innerVisible
            }
        }

    }

    Loader {
        id: sceneLoader
    }

    Connections {
        id: videoFramePaintedConnection
        ignoreUnknownSignals: true
    }

    function closeScene() {
        sceneSelectionPanel.sceneSource = ""
    }
}
