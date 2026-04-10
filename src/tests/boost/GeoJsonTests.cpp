#include <boost/test/unit_test.hpp>

#include "GeoJsonConverter.h"

#include <filesystem>
#include <list>
#include <string>
#include <fstream>

// Helper function to delete generated SVG files
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

// Fixture, each test case is primed with a selected map and projection, and generated files are deleted after each test
struct GeoJsonTestFixture {
	GeoJsonConverter converter;
	GeoJsonTestFixture() {
		converter.selectProjection("webMercator");
		converter.selectMap("worldMap");
		deleteGeneratedFiles();
	};
	~GeoJsonTestFixture() {
		deleteGeneratedFiles();
	}
};

// Helper function to compare the content of two SVG files
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

// Helper function to test if the SVG files are generated correctly and match the expected content
void svgCheck(const std::string& projection, const std::string& map) {
	BOOST_CHECK(std::filesystem::exists("resources/" + map + "_"+projection+".svg"));
	BOOST_CHECK(fileCheck(map, projection));
}

BOOST_AUTO_TEST_SUITE(GeoJsonTestSuite)

BOOST_AUTO_TEST_CASE(GEO_UT1_Constructor)
{
	BOOST_CHECK_NO_THROW(GeoJsonConverter{});
}

BOOST_FIXTURE_TEST_CASE(GEO_UT2_generateWebMercator, GeoJsonTestFixture)
{
	converter.selectProjection("webMercator");
	svgCheck("webMercator", "worldMap");
}

BOOST_FIXTURE_TEST_CASE(GEO_UT3_generateWGS84, GeoJsonTestFixture)
{
	converter.selectProjection("wgs84");
	svgCheck("wgs84", "worldMap");
}

BOOST_FIXTURE_TEST_CASE(GEO_UT4_generateGallStereographic, GeoJsonTestFixture)
{
	converter.selectProjection("gallStereographic");
	svgCheck("gallStereographic", "worldMap");
}

BOOST_FIXTURE_TEST_CASE(GEO_UT5_generateWinkelTripel, GeoJsonTestFixture)
{
	converter.selectProjection("winkelTripel");
	svgCheck("winkelTripel", "worldMap");
}

BOOST_FIXTURE_TEST_CASE(GEO_UT6_generateGallPeters, GeoJsonTestFixture)
{
	converter.selectProjection("gallPeters");
	svgCheck("gallPeters", "worldMap");
}

BOOST_FIXTURE_TEST_CASE(GEO_UT7_generateSinusoidal, GeoJsonTestFixture)
{
	converter.selectProjection("sinusoidal");
	svgCheck("sinusoidal", "worldMap");
}

BOOST_FIXTURE_TEST_CASE(GEO_UT8_generateEqualEarth, GeoJsonTestFixture)
{
	converter.selectProjection("equalEarth");
	svgCheck("equalEarth", "worldMap");
}

BOOST_FIXTURE_TEST_CASE(GEO_UT9_selectWorldMap, GeoJsonTestFixture)
{
	std::string projection = "webMercator";
	std::string selectedMap = "worldMap";

	converter.selectMap(QString::fromStdString(selectedMap));

	svgCheck(projection, selectedMap);
}

BOOST_FIXTURE_TEST_CASE(GEO_UT10_selectPangea, GeoJsonTestFixture)
{
	std::string projection = "webMercator";
	std::string selectedMap = "preHistoricMap";

	converter.selectMap(QString::fromStdString(selectedMap));

	svgCheck(projection, selectedMap);
}

BOOST_FIXTURE_TEST_CASE(GEO_UT11_selectMars, GeoJsonTestFixture)
{
	std::string projection = "webMercator";
	std::string selectedMap = "marsMap";

	converter.selectMap(QString::fromStdString(selectedMap));

	svgCheck(projection, selectedMap);
}

BOOST_FIXTURE_TEST_CASE(GEO_UT12_selectGrid, GeoJsonTestFixture)
{
	std::string projection = "webMercator";
	std::string selectedMap = "gridMap";

	converter.selectMap(QString::fromStdString(selectedMap));

	svgCheck(projection, selectedMap);
}

BOOST_AUTO_TEST_SUITE_END()