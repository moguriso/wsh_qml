#ifndef ITUNESCTRL_H
#define ITUNESCTRL_H

#include <QQuickItem>
#include <QAxScriptEngine>
#include <QAxScript>
#include <QDebug>

class ItunesCtrl : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(ItunesCtrl)

public:
    ItunesCtrl(QQuickItem *parent = 0);
    ~ItunesCtrl();

    Q_INVOKABLE QString getArtworkPath();
    Q_INVOKABLE bool nextTrack();

private:
    QAxScriptManager *m_manager;
    QAxScript *m_script;
};

#endif // ITUNESCTRL_H
