#include "Projections.h"
#include <cmath>

Projections::Projections(double x, double y)
{
	originalDegreesX = x;
	originalDegreesY = y;
	originalRadiansX = x * (M_PI / 180);
	originalRadiansY = y * (M_PI / 180);
	projectedX = 0;
	projectedY = 0;
}

void Projections::wgs84() { // upside-down top left
	projectedX = originalDegreesX + 180.0;// this also needs looking at, scaling and positioning
	projectedY = originalDegreesY + 90.0;
}

void Projections::webMercator() {
	// works in radians
	double lon = originalRadiansX;
	double lat = originalRadiansY;
	double x = (1 / (2 * (M_PI))) * (M_PI + lon);
	double y = (1/(2*(M_PI))*(M_PI - log(tan((M_PI / 4) + (lat / 2)))));
	projectedX = x * 800;
	projectedY = y * 800;
	// needs to be multiplied by same number as svg height and width, to scale properly. Should be a constant
}

void Projections::gallStereographic() { // same scaling issue as wgs84, upside-down top left
	// works in Radians
	double lon = originalRadiansX;
	double lat = originalRadiansY;

	int R = 100;

	double x = (R * lon) / sqrt(2);
	double y = R * (1 + (sqrt(2) / 2)) * tan(lat / 2);
	projectedX = x;
	projectedY = y;
}

//void Projections::winkelTripel() {
//	double lon = originalX;
//	double lat = originalY;
//
//	double a = acos(cos(lat) * cos(lon / 2));
//
//	double x = (1/2) *(lon*cos(lat)+((2 * cos(lat)) * (sin(lon / 2)))/sin(cos(a)));
//	double y = (1 / 2) * (lat + (sin(lat) / sin(cos(a))));
//	projectedX = x;
//	projectedY = y;
//}