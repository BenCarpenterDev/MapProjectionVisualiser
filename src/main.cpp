#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "GeoJsonConverter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<GeoJsonConverter>("GeoJsonConverter", 1, 0, "GeoJsonConverter");

    engine.load(QUrl(QStringLiteral("qrc:/src/gui/MainView.qml")));

    return app.exec();
}

