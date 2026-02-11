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
	double originalX;
	double originalY;
};	

#endif // PROJECTIONS_H