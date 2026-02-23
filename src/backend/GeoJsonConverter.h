#ifndef GEOJSONCONVERTER_H
#define GEOJSONCONVERTER_H

#include <QObject>
#include <QString>

#include <nlohmann/json.hpp>

/**
* @brief Converts JSON vector map data to SVG format.
*
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
	 * @brief Reads vector map data and converts it to SVG format using the specified projection.
     *
	 * This method read through every object within the JSON file, applies a projection algorithm to the coordinates and writes to an SVG file. 
     * If the SVG file already exists, it will not be created again and the existing file will be used instead.
     *
     * @param projection Projection choice to be applied to coordinates.
     *
     */
    Q_INVOKABLE void convertFile(const QString projection);

    /**
	 * @brief Outputs the SVG file path for the specified projection.
     *
     * Returns the files path of the cached/generated SVG file and emits a signal, ensuring the svg file is used on the frontend side.
     *
     * @param projection Projection choice to be applied to coordinates.
     *
     */
    Q_INVOKABLE QString outputSVG(const QString projection);

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

signals:
    /**
	* @brief Signal emitted when the SVG file is ready to be used on the frontend side.
    *
    * @param path File path of generated SVG file.
    *
    */
    void svgSignal(const QString& filePath);
};

#endif // GEOJSONCONVERTER_H