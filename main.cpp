#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <qqml.h>
#include "qdeclarativevideotee.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QDeclarativeVideoTee>("MyComponents", 1, 0, "VideoTee");

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/VideoTee/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
