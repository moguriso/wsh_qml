import QtQuick 2.5

Rectangle {
    id: _root

    function init_pos()
    {
        _img.anchors.rightMargin = 0
        _img.anchors.bottomMargin = 0
        _img.anchors.leftMargin = 0
        _img.anchors.topMargin = 0
        _img.anchors.fill = anchors.fill.parent
    }

    function set_artwork(path, w, h)
    {
        _img.source = path
        _img.width = w
        _img.height = h
    }

    function getWidth()
    {
        return _img.width;
    }

    function getHeight()
    {
        return _img.height;
    }

    Image {
        id: _img
        //anchors.fill: parent
        width: 0
        height: 0
    }
}
