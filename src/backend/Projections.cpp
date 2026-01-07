#include "Projections.h"
#include <cmath>

void Projections::webMercator() {

	double lon = originalX;
	double lat = originalY;
	double x = (1 / (2 * (M_PI))) * (M_PI + (lon * (M_PI / 180)));
	double y = (1/(2*(M_PI))*(M_PI - log(tan((M_PI / 4) + (lat * (M_PI / 180) / 2)))));
	projectedX = x;
	projectedY = y;
}