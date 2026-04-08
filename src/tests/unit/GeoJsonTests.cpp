#define BOOST_TEST_MODULE MapVisualiserTests
#include <boost/test/included/unit_test.hpp>

#include "GeoJsonConverter.h"

#include <filesystem>
#include <list>
#include <string>

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
		"shapesMap"
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

void primeTest(GeoJsonConverter& converter, const std::string& projection, const std::string& map) {
	deleteGeneratedFiles();
	converter.selectProjection(QString::fromStdString(projection));
	converter.selectMap(QString::fromStdString(map));
	BOOST_CHECK(std::filesystem::exists("resources/" + map + "_"+projection+".svg"));
	BOOST_CHECK(std::filesystem::exists("resources/gridMap_"+projection+".svg"));
}

BOOST_AUTO_TEST_SUITE(GeoJsonTestSuite)

BOOST_AUTO_TEST_CASE(GEO_UT1_Constructor)
{
	BOOST_CHECK_NO_THROW(GeoJsonConverter());
}

BOOST_AUTO_TEST_CASE(GEO_UT2)
{
	GeoJsonConverter converter;
	primeTest(converter, "webMercator", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT3)
{
	GeoJsonConverter converter;
	primeTest(converter, "wgs84", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT4)
{
	GeoJsonConverter converter;
	primeTest(converter, "gallStereographic", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT5)
{
	GeoJsonConverter converter;
	primeTest(converter, "winkelTripel", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT6)
{
	GeoJsonConverter converter;
	primeTest(converter, "gallPeters", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT7)
{
	GeoJsonConverter converter;
	primeTest(converter, "sinusoidal", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT8)
{
	GeoJsonConverter converter;
	primeTest(converter, "equalEarth", "worldMap");
}

BOOST_AUTO_TEST_SUITE_END()