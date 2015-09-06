#include <QApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include "httprequest.h"
#include "ftprequest.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<HttpRequest>("Httprequest",1,0,"Httprequest");
    qmlRegisterType<FtpRequest>("Ftprequest",1,0,"Ftprequest");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
