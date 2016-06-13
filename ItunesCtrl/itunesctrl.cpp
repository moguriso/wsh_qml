#include "itunesctrl.h"
#include "windows.h"
#include "objbase.h"

ItunesCtrl::ItunesCtrl(QQuickItem *parent):
    QQuickItem(parent)
{
#if 1
    m_manager = new QAxScriptManager(this);
    bool isRegistered = m_manager->registerEngine("VBScript", "vbs");
    if(isRegistered){
        //m_script = m_manager->load("file://C:/msys64/home/adachi/test.vbs", "HelloWorld");
        m_script = m_manager->load("C:\\msys64\\home\\adachi\\test.vbs", "HelloWorld");
        if(m_script)
            qDebug() << "OK to register VBScript";
        else
            qDebug() << "NG to register VBScript.";
    }
    else
        qDebug() << "NG to register VBScript";
#else
    m_manager = NULL;
#endif
}

ItunesCtrl::~ItunesCtrl()
{
    if(m_script)
        delete m_script;
    if(m_manager)
        delete m_manager;
}

QString ItunesCtrl::getArtworkPath()
{
    QString rStr = "";

#if 0
    if(!m_manager)
        m_manager = new QAxScriptManager(this);

    bool isRegistered = m_manager->registerEngine("VBScript", "vbs");
    if(isRegistered){
        m_script = m_manager->load("C:\\msys64\\home\\adachi\\test.vbs", "HelloWorld");
        if(m_script)
            qDebug() << "OK to register VBScript";
        else
            qDebug() << "NG to register VBScript.";
    }
    else
        qDebug() << "NG to register VBScript";
#endif
    if (m_script){
        QVariant var = m_script->call("getArtworkAndPath()");
        qDebug() << var.toString() << "loaded";
        rStr = var.toString();
        qDebug() << "rstr = " << rStr;
    }
    else
        qDebug() << "didn't load";

    return rStr;
}

bool ItunesCtrl::nextTrack()
{
    bool r_inf = false;
    QString rStr = "";

    if (m_script){
        m_script->call("nextTrack()");
        r_inf = true;
    }
    else
        qDebug() << "didn't load";

    return r_inf;
}

#if 0
void ItunesCtrl::on_pushButton_clicked()
{
    QString path = getArtworkPath();

    QImage img(600, 595, QImage::Format_RGB32);
    QImageReader qir("C:\\Users\\adachi\\AppData\\Local\\Temp\\a.jpg");
    bool isSuccess = qir.read(&img);
    if(isSuccess){
        QRect rect = QRect(0, 0, img.width(), img.height());
        QPainter widgetpainter( ui->graphicsView->viewport() );
        widgetpainter.drawImage(0,0,img);
        ui->graphicsView->viewport()->update();
    }
    else
        qDebug() << qir.errorString();
}

void ItunesCtrl::on_pushButton_2_clicked()
{
    if (m_script){
        m_script->call("nextTrack()");
        qDebug() << "loaded";
    }
    else
        qDebug() << "didn't load";
}
#endif

