#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Controller controller;

    controller.init();

    engine.rootContext()->setContextProperty("controller", &controller);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
