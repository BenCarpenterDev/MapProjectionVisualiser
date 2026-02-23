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
	svgBox = 800;
}

void Projections::normalise(double x, double y, double scale) {// there has to be a better way to this or explanation
	// different scale may be needed for different projections, different bounds may be used
	projectedX = (x * scale) + (svgBox / 2); // centres the map to the middle
	projectedY = ((y * scale) * -1) + (svgBox / 2); // centre the map to the middle and flips it upside down

	// 2 options for scale, have the projection width fit (/360) the box or its height (/180) fit the box
}

void Projections::wgs84() {
	normalise(originalDegreesX, originalDegreesY, svgBox/360);
}

void Projections::webMercator() {
	double lon = originalRadiansX;
	double lat = originalRadiansY;
	double x = (1 / (2 * (M_PI))) * (M_PI + lon);
	double y = (1/(2*(M_PI))*(M_PI - log(tan((M_PI / 4) + (lat / 2)))));
	projectedX = x * svgBox;
	projectedY = y * svgBox;
}

void Projections::gallStereographic() {
	double lon = originalRadiansX;
	double lat = originalRadiansY;

	int R = 180;// radius of the globe

	double x = (R * lon) / sqrt(2);
	double y = R * (1 + (sqrt(2) / 2)) * tan(lat / 2);

	normalise(x, y, 1); // this projection already is being multiplied by the radius, so scale is 1, 
	//but it still needs to be normalised to fit in the svg box and flipped upside down
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