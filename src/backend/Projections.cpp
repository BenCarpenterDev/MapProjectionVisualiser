#include "Projections.h"
#include <cmath>

Projections::Projections(double x, double y)
{
	originalX = x;
	originalY = y;
	projectedX = 0;
	projectedY = 0;
}

void Projections::wgs84() {
	projectedX = originalX + 180.0;// this also needs looking at, scaling and positioning
	projectedY = originalY + 90.0;
}

void Projections::webMercator() {

	double lon = originalX;
	double lat = originalY;
	double x = (1 / (2 * (M_PI))) * (M_PI + (lon * (M_PI / 180)));
	double y = (1/(2*(M_PI))*(M_PI - log(tan((M_PI / 4) + (lat * (M_PI / 180) / 2)))));
	projectedX = x * 800;
	projectedY = y*800;
	// needs to be multiplied by same number as svg height and width, to scale properly. Should be a constant
}