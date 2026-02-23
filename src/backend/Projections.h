#ifndef PROJECTIONS_H
#define PROJECTIONS_H

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

/**
* @brief Stores current coordinates and applies projection algorithms to them.
*
*/
class Projections
{
public:
	/**
	* @brief Constructor for Projections class, stores original coordinates from the JSON file, in both degrees and radians
	*
	* @param x original x coordinate
	* @param y original y coordinate
	*/
	Projections(double x, double y);
	/**
	* @brief Currently projected x coordinate
	*/
	double projectedX;
	/**
	* @brief Currently projected y coordinate
	*/
	double projectedY;
	/**
	 * @brief The Web Mercator projection
	 *
	 * Applies web mercator projection algorithm, works in radians
	 * Additonal Note: Needs to be multiplied by same number as svg height and width, to scale properly. 
	 *
	 */
	void webMercator();
	/**
	 * @brief The WGS84 projection
	 *
	 * Applies original json coordinates, works in degrees
	 * Additonal Note: This coordinate system has bounds of -180 to 180 and -90 to 90, so scaling by svgBox/360 means that the map will fit within the svg box.
	 *
	 */
	void wgs84();
	/**
	 * @brief The Gall Stereographic projection
	 *
	 * Applies gall stereographic projection algorithm, works in radians
	 * Additonal Note: This projection already is being multiplied by the radius, so scale is 1, but it still needs to be normalised to fit in the svg box.
	 *
	 */
	void gallStereographic();
	//void winkelTripel();

private:
	/**
	* @brief Original x coordinate from the JSON file, in degrees
	*/
	double originalDegreesX;
	/**
	* @brief Original y coordinate from the JSON file, in degrees
	*/
	double originalDegreesY;
	/**
	* @brief Original x coordinate from the JSON file, in radians
	*/
	double originalRadiansX;
	/**
	* @brief Original y coordinate from the JSON file, in radians
	*/
	double originalRadiansY;
	/**
	* @brief Width and height of the SVG box, used for normalisation of projected coordinates to fit within the box.
	*/
	double svgBox;

	/**
	 * @brief Normalises the projected coordinates to fit within the SVG box
	 * 
	 * This centres the map and flips it upside down
	 *
	 * @param x The x coordinate after projection
	 * @param y The y coordinate after projection
	 * @param scale The scale factor to be applied to the projected coordinates, which may vary for different projections
	 *
	 */
	void normalise(double x, double y, double scale);
};	

#endif // PROJECTIONS_H