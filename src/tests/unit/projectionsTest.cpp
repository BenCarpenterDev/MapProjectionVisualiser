#define BOOST_TEST_MODULE MapVisualiserTests
#include <boost/test/included/unit_test.hpp>
#include "../../backend/Projections.h"

BOOST_AUTO_TEST_SUITE(ProjectionsTestSuite)

Projections upperRight(180, 90);
Projections lowerRight(180, -90);
Projections upperLeft(-180, 90);
Projections lowerLeft(-180, -90);

BOOST_AUTO_TEST_CASE(PROJ_UT1_Constructor)
{
	int xTestNormal = 23;
	int yTestNormal = 40;
	Projections proj(xTestNormal, yTestNormal);

	BOOST_CHECK_EQUAL((proj.projectedX), 0);
	BOOST_CHECK_EQUAL((proj.projectedY), 0);
}

BOOST_AUTO_TEST_CASE(PROJ_UT2_applyWebMercator)
{
	std::string wmSelection = "webMercator";
	upperRight.applyProjection(wmSelection);
	lowerRight.applyProjection(wmSelection);
	upperLeft.applyProjection(wmSelection);
	lowerLeft.applyProjection(wmSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 800);
	BOOST_CHECK_EQUAL((upperRight.projectedY), -4353.239558363628);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 800);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 4353.239558363628);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 0);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), -4353.239558363628);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 0);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 4353.239558363628);
}

BOOST_AUTO_TEST_CASE(PROJ_UT3_applyWgs84)
{
	std::string wgs84Selection = "wgs84";
	upperRight.applyProjection(wgs84Selection);
	lowerRight.applyProjection(wgs84Selection);
	upperLeft.applyProjection(wgs84Selection);
	lowerLeft.applyProjection(wgs84Selection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 760);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 220);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 760);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 580);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 40);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 220);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 40);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 580);
}

BOOST_AUTO_TEST_CASE(PROJ_UT4_applyGallStereographic)
{
	std::string gsSelection = "gallStereographic";
	upperRight.applyProjection(gsSelection);
	lowerRight.applyProjection(gsSelection);
	upperLeft.applyProjection(gsSelection);
	lowerLeft.applyProjection(gsSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 799.85946443425291);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 92.720779386421498);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 799.85946443425291);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 707.27922061357845);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 0.14053556574708637);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 92.720779386421498);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 0.14053556574708637);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 707.27922061357845);
}

BOOST_AUTO_TEST_CASE(PROJ_UT5_applyWinkelTripel)
{
	std::string wtSelection = "winkelTripel";
	upperRight.applyProjection(wtSelection);
	lowerRight.applyProjection(wtSelection);
	upperLeft.applyProjection(wtSelection);
	lowerLeft.applyProjection(wtSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 580);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 117.25666117691861);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 580);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 682.74333882308133);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 220);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 117.25666117691861);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 220);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 682.74333882308133);
}

BOOST_AUTO_TEST_CASE(PROJ_UT6_applyGallPeters)
{
	std::string gpSelection = "gallPeters";
	upperRight.applyProjection(gpSelection);
	lowerRight.applyProjection(gpSelection);
	upperLeft.applyProjection(gpSelection);
	lowerLeft.applyProjection(gpSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 965.48667764616278);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 40);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 965.48667764616278);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 760);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), -165.48667764616278);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 40);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), -165.48667764616278);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 760);
}

BOOST_AUTO_TEST_CASE(PROJ_UT7_applySinusoidal)
{
	std::string siSelection = "sinusoidal";
	upperRight.applyProjection(siSelection);
	lowerRight.applyProjection(siSelection);
	upperLeft.applyProjection(siSelection);
	lowerLeft.applyProjection(siSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 400.00000000000006);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 117.25666117691861);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 400.00000000000006);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 682.74333882308133);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 399.99999999999994);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 117.25666117691861);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 399.99999999999994);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 682.74333882308133);
}

BOOST_AUTO_TEST_CASE(PROJ_UT8_applyEqualEarth)
{
	std::string eeSelection = "equalEarth";
	upperRight.applyProjection(eeSelection);
	lowerRight.applyProjection(eeSelection);
	upperLeft.applyProjection(eeSelection);
	lowerLeft.applyProjection(eeSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 634.15609264112254);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 162.87470335166566);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 651.15347055535403);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 637.12529664833437);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 165.8439073588774);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 162.87470335166566);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 148.84652944464599);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 637.12529664833437);
}

BOOST_AUTO_TEST_SUITE_END()