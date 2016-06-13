import QtQuick 2.5
import QtQuick.Window 2.2
import com.moguriso.qmlcomponents 1.0

Window {
    id: mainWindow
    visible: true
    width: 320
    height: 320

    MainForm {
        property string artwork_path
        anchors.fill: parent

        Component.onCompleted: {
            //console.log("x = " + xxx + "y = " + yyy);

            artwork_path = ituneCtrl.getArtworkPath();
            console.log("path = " + artwork_path);

            do{
                artwork_path = artwork_path.replace("\\", "/");
            } while(artwork_path.indexOf("\\") != -1);
            artwork_path = "file:///" + artwork_path;

            console.log("path = " + artwork_path);
            _artwork.set_artwork(artwork_path,
                                 Window.width, Window.height);
//          _artwork.set_artwork("file:///C:/Users/adachi/AppData/local/temp/a.jpg",
//                               Window.width, Window.height);
            _artwork.init_pos(0);

            //console.log("width = " + width + "height = " + height);
            //
            //xxx: _artwork.getWidth()
            //yyy: _artwork.getHeight()
            //width: _artwork.getWidth()
            //height: _artwork.getHeight()
            //console.log("x = " + xxx + "y = " + yyy);
            //console.log("width = " + width + "height = " + height);
        }

        mouseArea1.onClicked:{
            ituneCtrl.nextTrack();
        }

        ItunesCtrl{
            id: ituneCtrl
        }
    }
}

