#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <filesystem>

#include "GeoJsonConverter.h"

class Setup : public QObject
{
    Q_OBJECT

public:
    Setup() {}

private:
	void deleteGeneratedFiles() {
		std::list<std::string> projections = {
			"wgs84",
			"webMercator",
			"gallStereographic",
			"winkelTripel",
			"gallPeters",
			"sinusoidal",
			"equalEarth"
		};

		std::list<std::string> maps = {
			"worldMap",
			"gridMap",
			"preHistoricMap",
			"shapesMap",
			"marsMap"
		};
		for (std::string projection : projections) {
			for (std::string map : maps) {
				std::string filePath = "resources/" + map + "_" + projection + ".svg";
				if (std::filesystem::exists(filePath)) {
					std::filesystem::remove(filePath);
				}
			}
		};
	}

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

	void initTestCase()
	{
		deleteGeneratedFiles();
	}

    void cleanupTestCase()
    {
		deleteGeneratedFiles();
    }
};

QUICK_TEST_MAIN_WITH_SETUP(MapProjectionGUITests, Setup)

#include "mainQuickTests.moc"