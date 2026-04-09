#ifndef GEOJSONCONVERTER_H
#define GEOJSONCONVERTER_H

#include <QObject>
#include <QString>

#include <nlohmann/json.hpp>

/**
* @brief Converts JSON vector map data to SVG format.
*/
class GeoJsonConverter : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Initializes GeoJsonConverter object.
     *
     * @param *parent The parent QObject, default is nullptr.
     *
     */
    explicit GeoJsonConverter(QObject *parent = nullptr);

    /**
     * @brief Allows frontend to change chosen projection
     *
     * @param projection QML String for selected map projection.
     *
     */
    Q_INVOKABLE void selectProjection(const QString projection);

    /**
     * @brief Allows frontend to change chosen map
     *
     * @param projection QML String for selected map.
     *
     */
    Q_INVOKABLE void selectMap(const QString map);

private:
    /**
	 * @brief Read the GeoJSON file and parse it into a JSON object.
     *
	 * Returns a JSON object, using the nlohmann::json library.
     *
	 * @param path File path of the GeoJSON file to be read.
     *
     */
    nlohmann::json readFile(const std::string path);

    /**
	* @brief Checks if specified file exists.
    *
    * Returns a boolean value on whether the file exists or not.
    *
	* @param path File path to check for existence.
    *
    */
    bool checkFileExists(const std::string path);

    /**
	* @brief Formats the content of the JSON file into SVG format using the specified projection and styling.
    *
	* This method iterates through each feature in the JSON file, applies the chosen projection to the coordinates, 
    * and writes the corresponding SVG elements to the provided string stream. The fill and stroke colours for the SVG elements can be specified as parameters.
    *
	* @param svgStream The string stream to which the SVG content will be written.
	* @param jsonFile The JSON object containing the vector map data to be converted.
	* @param fillColour The fill colour to be applied to the SVG elements.
	* @param strokeColour The stroke colour to be applied to the SVG elements.
    *
    */
    void svgContentFormat(std::ostringstream& svgStream, nlohmann::json jsonFile, std::string fillColour, std::string strokeColour);

    /**
    * @brief Reads vector map data and converts it to SVG format using the specified projection.
    *
    * This method read through every object within the JSON file, applies a projection algorithm to the coordinates and writes to an SVG file.
    * If the SVG file already exists, it will not be created again and the existing file will be used instead.
    *
    * @param selectedMap Determines which map is read and converted.
    *
    */
    void convertFile(std::string selectedMap);

    /**
     * @brief Outputs the SVG file path for the specified projection.
     *
     * Emits a signal, ensuring the svg file is used on the frontend side.
     *
     */
    void outputSVG();

    /**
     * @brief Stores currently selected map.
     *
     */
    std::string currentMap;

    /**
     * @brief Stores currently selected map projection.
     *
     */
    std::string currentProjection;

signals:
    /**
	* @brief Signal emitted when the maps's SVG file is ready to be used on the frontend side.
    *
    * @param path File path of generated map SVG file.
    *
    */
    void mapChanged(const QString& filePath);

    /**
    * @brief Signal emitted when the grid's SVG file is ready to be used on the frontend side.
    *
    * @param path File path of generated grid SVG file.
    *
    */
    void gridChanged(const QString& filePath);

    /**
    * @brief Signal emitted when the projection has changed and needs to be reflected on the frontend side.
    *
    * @param path String of chosen map projection.
    *
    */
    void projectionChanged(const QString& projection);
};

#endif // GEOJSONCONVERTER_H