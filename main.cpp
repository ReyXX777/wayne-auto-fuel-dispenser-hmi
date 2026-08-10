#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>
#include "src/model/fm.h"
#include "src/controller/dc.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    FuelDispenserModel model;
    DispenserController controller;
    controller.setModel(&model);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("fuelModel", &model);
    engine.rootContext()->setContextProperty("dispenserController", &controller);

    const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,
        [url, &controller](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) {
                qCritical() << "FATAL QML load failed";
                QCoreApplication::exit(-1);
            }
            if (obj && url == objUrl) {
                QTimer::singleShot(500, &controller, &DispenserController::startAutomatedDemo);
            }
        }, Qt::QueuedConnection);

    engine.load(url);
    return app.exec();
}