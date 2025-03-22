import QtQuick

Item {
    ListView{
            id : mListViewId
            anchors.fill: parent

           // model: continentModel
            //model: itemList1
            model: itemList2
            delegate: Rectangle {
                height: 50
                radius: 10
                color: "dodgerblue"
                border.color: "cyan"
                width: (parent === null ?  rootId.width  : parent.width)

                Text {
                    text: modelData
                    font.pointSize: 20
                    anchors.centerIn: parent
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
}
