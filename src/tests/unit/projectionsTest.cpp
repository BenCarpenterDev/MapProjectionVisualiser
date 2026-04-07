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

std::string wmSelection = "webMercator";
BOOST_AUTO_TEST_CASE(PROJ_UT2_applyWebMercator)
{

	upperRight.applyProjection(wmSelection);
	lowerRight.applyProjection(wmSelection);
	upperLeft.applyProjection(wmSelection);
	lowerLeft.applyProjection(wmSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 800);
	BOOST_CHECK_EQUAL((upperRight.projectedY), -4353.239558363628);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 800);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 2762.7359442834086);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 0);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), -4353.239558363628);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 0);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 2762.7359442834086);
}

std::string wgs84Selection = "wgs84";
BOOST_AUTO_TEST_CASE(PROJ_UT3_applyWgs84)
{

	upperRight.applyProjection(wgs84Selection);
	lowerRight.applyProjection(wgs84Selection);
	upperLeft.applyProjection(wgs84Selection);
	lowerLeft.applyProjection(wgs84Selection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 760);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 220);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 760);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 579.99999800000001);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 40);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 220);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 40);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 579.99999800000001);
}

std::string gsSelection = "gallStereographic";
BOOST_AUTO_TEST_CASE(PROJ_UT4_applyGallStereographic)
{

	upperRight.applyProjection(gsSelection);
	lowerRight.applyProjection(gsSelection);
	upperLeft.applyProjection(gsSelection);
	lowerLeft.applyProjection(gsSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 799.85946443425291);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 92.720779386421498);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 799.85946443425291);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 707.27921525054444);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 0.14053556574708637);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 92.720779386421498);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 0.14053556574708637);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 707.27921525054444);
}

std::string wtSelection = "winkelTripel";
BOOST_AUTO_TEST_CASE(PROJ_UT5_applyWinkelTripel)
{

	upperRight.applyProjection(wtSelection);
	lowerRight.applyProjection(wtSelection);
	upperLeft.applyProjection(wtSelection);
	lowerLeft.applyProjection(wtSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 580);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 117.25666117691861);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 580.00000493480218);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 682.74333725228507);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 220);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 117.25666117691861);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 219.99999506519782);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 682.74333725228507);
}

std::string wtSelection = "winkelTripel";
BOOST_AUTO_TEST_CASE(PROJ_UT4_applyWinkelTripel)
{

	upperRight.applyProjection(wtSelection);
	lowerRight.applyProjection(wtSelection);
	upperLeft.applyProjection(wtSelection);
	lowerLeft.applyProjection(wtSelection);

	BOOST_CHECK_EQUAL((upperRight.projectedX), 580);
	BOOST_CHECK_EQUAL((upperRight.projectedY), 117.25666117691861);
	BOOST_CHECK_EQUAL((lowerRight.projectedX), 580.00000493480218);
	BOOST_CHECK_EQUAL((lowerRight.projectedY), 682.74333725228507);
	BOOST_CHECK_EQUAL((upperLeft.projectedX), 220);
	BOOST_CHECK_EQUAL((upperLeft.projectedY), 117.25666117691861);
	BOOST_CHECK_EQUAL((lowerLeft.projectedX), 219.99999506519782);
	BOOST_CHECK_EQUAL((lowerLeft.projectedY), 682.74333725228507);
}

BOOST_AUTO_TEST_SUITE_END()