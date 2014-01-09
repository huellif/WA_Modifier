#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeEngine>
#include <QDeclarativeContext>

#include "helper.h"

#include <QtGui/QSplashScreen>
#include <QtGui/QPixmap>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Splashscreen
    QSplashScreen *splash = new QSplashScreen(QPixmap(":/splash.jpg"), Qt::WindowStaysOnTopHint);
    splash->show();
    splash->showMessage("Loading ...", Qt::AlignHCenter | Qt::AlignBottom, Qt::white);

    //creatining UI object
    QDeclarativeView viewer;

    //loading helper class for QtQuick UI to Qt/C++ access
    Helper helper;
    viewer.rootContext()->setContextProperty("Helper", &helper);

    //performance tweaks
    viewer.setAttribute(Qt::WA_OpaquePaintEvent);
    viewer.setAttribute(Qt::WA_NoSystemBackground);
    viewer.viewport()->setAttribute(Qt::WA_OpaquePaintEvent);
    viewer.viewport()->setAttribute(Qt::WA_NoSystemBackground);

    //loading main.qml
    viewer.setSource(QUrl(QLatin1String("qrc:/qml/main.qml")));
    viewer.showFullScreen();

    //remove splashscreen overlay
    delete splash;

    //conecting the close signal
    QObject::connect(viewer.engine(), SIGNAL(quit()), &viewer, SLOT(close()));

    //app has to stay alive
    return app.exec();
}
