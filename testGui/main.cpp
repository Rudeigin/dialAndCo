#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include "core.h"
#include <dialmodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Core core;
    QQmlApplicationEngine engine;
    QQmlContext *context=engine.rootContext();
    context->setContextProperty("core",&core);

    qmlRegisterType<DialModel>("ru.fo.dialcore", 1, 0, "DialModel");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
