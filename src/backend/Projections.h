#ifndef PROJECTIONS_H
#define PROJECTIONS_H

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

class Projections
{
public:
	Projections(double x, double y);

	double projectedX;
	double projectedY;
	void webMercator();
	void gallStereographic();
	//void winkelTripel();
	void wgs84();

private:
	double originalDegreesX;
	double originalDegreesY;
	double originalRadiansX;
	double originalRadiansY;
	double svgBox;

	void normalise(double x, double y, double scale);
};	

#endif // PROJECTIONS_H