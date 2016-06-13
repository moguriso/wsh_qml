#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "itunesctrl.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<ItunesCtrl>("com.moguriso.qmlcomponents", 1, 0, "ItunesCtrl");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
