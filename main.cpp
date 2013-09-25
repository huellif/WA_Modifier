#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include "helper.h"
#include <QtGui/QSplashScreen>
#include <QtGui/QPixmap>


int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    //Splashscreen
    QSplashScreen *splash = new QSplashScreen(QPixmap(":/splash.jpg"));
    splash->show();
    splash->showMessage("Loading ...", Qt::AlignHCenter | Qt::AlignBottom, Qt::white);

    //creatining UI object
    QmlApplicationViewer viewer;

    //loading helper class for QtQuick UI to Qt/C++ access
    Helper helper;
    viewer.setResizeMode(QDeclarativeView::SizeRootObjectToView);
    viewer.rootContext()->setContextProperty("Helper", &helper);

    //performance tweaks
    viewer.setAttribute(Qt::WA_OpaquePaintEvent);
    viewer.setAttribute(Qt::WA_NoSystemBackground);
    viewer.viewport()->setAttribute(Qt::WA_OpaquePaintEvent);
    viewer.viewport()->setAttribute(Qt::WA_NoSystemBackground);

    //loading main.qml
    viewer.setSource(QUrl("qrc:/qml/main.qml"));
    viewer.showFullScreen();

    //remove splashscreen overlay
    splash->finish(&viewer);
    splash->deleteLater();

    //app has to stay alive ;)
    return app->exec();
}
