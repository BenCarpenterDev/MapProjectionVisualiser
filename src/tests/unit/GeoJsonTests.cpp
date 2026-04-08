#include <boost/test/included/unit_test.hpp>
#include "../../backend/Projections.h"

BOOST_AUTO_TEST_SUITE(GeoJsonTestSuite)

BOOST_AUTO_TEST_CASE(GEO_UT1_Constructor)
{
	int xTestNormal = 23;
	int yTestNormal = 40;
	Projections proj(xTestNormal, yTestNormal);

	BOOST_CHECK_EQUAL((proj.projectedX), 0);
	BOOST_CHECK_EQUAL((proj.projectedY), 0);
}

BOOST_AUTO_TEST_SUITE_END()