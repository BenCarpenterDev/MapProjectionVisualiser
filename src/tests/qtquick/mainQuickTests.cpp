#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "GeoJsonConverter.h"

class Setup : public QObject
{
    Q_OBJECT

public:
    Setup() {}

public slots:

    void applicationAvailable()
    {
        // Initialization that only requires the QGuiApplication object to be available
        qmlRegisterType<GeoJsonConverter>("GeoJsonConverter", 1, 0, "GeoJsonConverter");
        QQmlApplicationEngine engine;
        engine.load(QUrl(QStringLiteral("qrc:/src/gui/MainView.qml")));

    }

    void qmlEngineAvailable(QQmlEngine* engine)
    {
        // Initialization requiring the QQmlEngine to be constructed
        engine->rootContext()->setContextProperty("myContextProperty", QVariant(true));
    }

    void cleanupTestCase()
    {
        // Implement custom resource cleanup
    }
};

QUICK_TEST_MAIN_WITH_SETUP(mytest, Setup)

#include "mainQuickTests.moc"