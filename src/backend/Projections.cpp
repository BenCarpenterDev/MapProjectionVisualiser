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

void Projections::applyProjection(const std::string projection) {
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
	else if (projection == "sinusoidal") {
		sinusoidal();
	}
	else if (projection == "equalEarth") {
		equalEarth();
	}
	else if (projection == "azimuthalEquidistant") {
		azimuthalEquidistant();
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

void Projections::sinusoidal() {
	double lon = originalRadiansX;
	double lat = originalRadiansY;

	double x = lon * cos(lat);

	normalise(x, lat, R);
}

void Projections::equalEarth() {
	double lon = originalRadiansX;
	double lat = originalRadiansY;

	double A1 = 1.340264;
	double A2 = -0.081106;
	double A3 = 0.000893;
	double A4 = 0.003796;

	double theta = asin((sqrt(3) / 2) * sin(lat));
	double theta9 = pow(theta, 9);
	double theta8 = pow(theta, 8);
	double theta7 = pow(theta, 7);
	double theta6 = pow(theta, 6);
	double theta3 = pow(theta, 3);
	double theta2 = pow(theta, 2);

	double x = (2 * sqrt(3) * lon * cos(theta)) / (3 * (9 * A4 * theta7 + 7 * A3 * theta2 + A1));
	double y = A4 * theta9 + A3 * theta7 + A2 * theta3 + A1 * theta;

	normalise(x, y, R);
}

void Projections::azimuthalEquidistant() {
	double lon = originalRadiansX;
	double lat = originalRadiansY;

	double p = R * ((M_PI / 2) - lat);

	double x = p * sin(lon);
	double y = -p * cos(lon);

	normalise(x, y, 1);
}