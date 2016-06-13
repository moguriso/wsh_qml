QT += qml quick
QT += axcontainer
CONFIG += qt plugin

INCLUDEPATH += ./ItunesCtrl
# Input
SOURCES += \
    ./ItunesCtrl/itunesctrl.cpp

HEADERS += \
    ./ItunesCtrl/itunesctrl.h

DISTFILES = qmldir

