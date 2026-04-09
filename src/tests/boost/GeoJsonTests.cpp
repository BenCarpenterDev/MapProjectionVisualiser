#include <boost/test/unit_test.hpp>

#include "GeoJsonConverter.h"

#include <filesystem>
#include <list>
#include <string>
#include <fstream>

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

bool fileCheck(const std::string& map, const std::string& projection) {
	std::string originalPath = "resources/" + map + "_" + projection + ".svg";
	std::string generatedPath = std::string(TEST_RESOURCES_DIR) + "/" + map + "_" + projection + ".svg";

	std::ifstream originalFile(originalPath);

	std::ifstream newFile(generatedPath);

	std::ostringstream originalString, newString;

	originalString << originalFile.rdbuf();
	newString << newFile.rdbuf();

	return originalString.str() == newString.str();
}

void svgTest(GeoJsonConverter& converter, const std::string& projection, const std::string& map) {
	deleteGeneratedFiles();
	converter.selectProjection(QString::fromStdString(projection));
	converter.selectMap(QString::fromStdString(map));
	BOOST_CHECK(std::filesystem::exists("resources/" + map + "_"+projection+".svg"));
	BOOST_CHECK(std::filesystem::exists("resources/gridMap_"+projection+".svg"));
	BOOST_CHECK(fileCheck(map, projection));
	BOOST_CHECK(fileCheck("gridMap", projection));
}

BOOST_AUTO_TEST_SUITE(GeoJsonTestSuite)

BOOST_AUTO_TEST_CASE(GEO_UT1_Constructor)
{
	BOOST_CHECK_NO_THROW(GeoJsonConverter{});
}

BOOST_AUTO_TEST_CASE(GEO_UT2_generateWebMercator)
{
	GeoJsonConverter converter;
	svgTest(converter, "webMercator", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT3_generateWGS84)
{
	GeoJsonConverter converter;
	svgTest(converter, "wgs84", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT4_generateGallStereographic)
{
	GeoJsonConverter converter;
	svgTest(converter, "gallStereographic", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT5_generateWinkelTripel)
{
	GeoJsonConverter converter;
	svgTest(converter, "winkelTripel", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT6_generateGallPeters)
{
	GeoJsonConverter converter;
	svgTest(converter, "gallPeters", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT7_generateSinusoidal)
{
	GeoJsonConverter converter;
	svgTest(converter, "sinusoidal", "worldMap");
}

BOOST_AUTO_TEST_CASE(GEO_UT8_generateEqualEarth)
{
	GeoJsonConverter converter;
	svgTest(converter, "equalEarth", "worldMap");
}

BOOST_AUTO_TEST_SUITE_END()