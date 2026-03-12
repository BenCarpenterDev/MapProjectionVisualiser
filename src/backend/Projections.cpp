#include "Projections.h"
#include <cmath>

constexpr int SVGBOX = 800;
constexpr int R = 180;
constexpr double M_PI = 3.14159265358979323846;

Projections::Projections(double x, double y)
{
	originalDegreesX = x;
	originalDegreesY = y;
	originalRadiansX = x * (M_PI / 180);
	originalRadiansY = y * (M_PI / 180);
	projectedX = 0;
	projectedY = 0;
}

void Projections::applyProjection(const QString projection) {
	if (projection == "wgs84") {
		wgs84();
	}
	else if (projection == "webMercator") {
		webMercator();
	}
	else if (projection == "gallStereographic") {
		gallStereographic();
	}
	else if (projection == "winkelTripel") {
		winkelTripel();
	}
	else if (projection == "gallPeters") {
		gallPeters();
	}
}

void Projections::normalise(double x, double y, double scale) {// there has to be a better way to this or explanation
	// different scale may be needed for different projections, different bounds may be used
	projectedX = (x * scale) + (SVGBOX / 2); // centres the map to the middle
	projectedY = ((y * scale) * -1) + (SVGBOX / 2); // centre the map to the middle and flips it upside down

	// 2 options for scale, have the projection width fit (/360) the box or its height (/180) fit the box
}

void Projections::wgs84() {
	normalise(originalDegreesX, originalDegreesY, SVGBOX /360);
}

void Projections::webMercator() {
	double lon = originalRadiansX;
	double lat = originalRadiansY;
	double x = (1 / (2 * (M_PI))) * (M_PI + lon);
	double y = (1/(2*(M_PI))*(M_PI - log(tan((M_PI / 4) + (lat / 2)))));
	projectedX = x * SVGBOX;
	projectedY = y * SVGBOX;
}

void Projections::gallStereographic() {
	double lon = originalRadiansX;
	double lat = originalRadiansY;

	double x = (R * lon) / sqrt(2);
	double y = R * (1 + (sqrt(2) / 2)) * tan(lat / 2);

	normalise(x, y, 1); // this projection already is being multiplied by the radius, so scale is 1, 
	//but it still needs to be normalised to fit in the svg box and flipped upside down
}

void Projections::winkelTripel(){
	double lon = originalRadiansX;
	double lat = originalRadiansY;

	double a = acos(cos(lat) * cos(lon / 2));
	double sincA = sin(a) / a;
	double parallel = acos(2 / M_PI);

	double x = 0.5 * ((lon * cos(parallel)) + ((2*cos(lat)*sin(lon/2)/sincA)));
	double y = 0.5 * (lat + (sin(lat) / sincA));

	normalise(x, y, R);
}

void Projections::gallPeters() {
	double lon = originalRadiansX;
	double lat = originalRadiansY;

	double x = R * lon;
	double y = 2 * R * sin(lat);

	normalise(x, y, 1);
}