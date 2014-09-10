#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <controller.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Controller controller;

    controller.init();

    engine.rootContext()->setContextProperty("controller", &controller);
    engine.rootContext()->setContextProperty("oxVuIn", controller.oxVuIn());
    engine.rootContext()->setContextProperty("oxVuOut", controller.oxVuOut());
    engine.rootContext()->setContextProperty("oxEqualizer", controller.oxEqualizer());

    engine.load(QUrl(QStringLiteral("qrc:///qml/main.qml")));

    return app.exec();
}
