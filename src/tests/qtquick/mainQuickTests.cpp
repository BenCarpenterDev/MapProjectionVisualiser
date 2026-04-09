#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>
#include <QGuiApplication>

class Setup : public QObject
{
    Q_OBJECT

public:
    Setup() {}

public slots:
    void applicationAvailable()
    {
        // Initialization that only requires the QGuiApplication object to be available
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