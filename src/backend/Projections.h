#ifndef PROJECTIONS_H
#define PROJECTIONS_H

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

class Projections
{
public:
	double originalX;
	double originalY;

	double projectedX;
	double projectedY;

private:
	void webMercator();
};	

#endif // PROJECTIONS_H