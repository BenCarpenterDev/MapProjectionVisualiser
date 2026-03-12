#include "GeoJsonConverter.h"
#include "Projections.h"

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <QString>
#include <QFileInfo>
#include <QDebug>

using json = nlohmann::json;

GeoJsonConverter::GeoJsonConverter(QObject *parent) : QObject(parent)
{
}

json GeoJsonConverter::readFile(const std::string path)
{
    std::ifstream file(path);
    json geoJson = json::parse(file);
    return geoJson;
}

bool GeoJsonConverter::checkFileExists(const std::string path) {
    std::ifstream file(path);
	return file.good();
}

Q_INVOKABLE void GeoJsonConverter::convertFile(const QString projection)
{
    std::string fileName = "resources/output" + projection.toStdString() + ".svg";
	if (!checkFileExists(fileName)) { // if cached svg file doesn't exist, create it
        std::ostringstream svgStream;
        svgStream << std::fixed << std::setprecision(7);

        svgStream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << 800 << "\" height=\"" << 800 << "\">\n";
        svgStream << "<rect width=\"" << 800 << "\" height=\"" << 800 << "\" fill=\"transparent\"/>\n";
        // should put height and width as constants

        json geoJson = readFile("resources/ne_110m_land.json");

        for (const auto& feature : geoJson["features"]) {
            const auto& geometry = feature["geometry"];
            const auto& type = geometry["type"];

            if (type == "Polygon") {
                for (const auto& polygon : geometry["coordinates"]) {
                    svgStream << "<polygon points=\"";
                    for (const auto& point : polygon) {
                        Projections coordinates(point[0].get<double>(), point[1].get<double>());

                        if (projection == "wgs84") {
                            coordinates.wgs84();
                        }
                        else if (projection == "webMercator") {
                            coordinates.webMercator();
                        }
                        else if (projection == "gallStereographic") {
                            coordinates.gallStereographic();
                        }
                        else if (projection == "winkelTripel") {
                            coordinates.winkelTripel();
                        }
                        svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
                    }
                    svgStream << "\" fill=\"#4CAF50\" stroke=\"#333\" stroke-width=\"0.1\"/>\n";
                }
            }
            else if (type == "MultiPolygon") {
                for (const auto& multipolygon : geometry["coordinates"]) {
                    for (const auto& polygon : multipolygon) {
                        svgStream << "<polygon points=\"";
                        for (const auto& point : polygon) {
                            Projections coordinates(point[0].get<double>(), point[1].get<double>());

                            if (projection == "wgs84") {
                                coordinates.wgs84();
                            }
                            else if (projection == "webMercator") {
                                coordinates.webMercator();
                            }
                            else if (projection == "gallStereographic") {
                                coordinates.gallStereographic();
                            }
                            else if (projection == "winkelTripel") {
                                coordinates.winkelTripel();
                            }
                            svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
                        }
                        svgStream << "\" fill=\"#4CAF50\" stroke=\"#333\" stroke-width=\"0.1\"/>\n";
                    }
                }
            }
        }

        svgStream << "</svg>\n";
        std::ofstream svgFile(fileName);
        svgFile << svgStream.str();
        svgFile.close();
    }
    outputSVG(projection);
}

Q_INVOKABLE QString GeoJsonConverter::outputSVG(const QString projection)
{
    QString filePath = "file:///" + QFileInfo("resources/output"+projection+".svg").absoluteFilePath();
    qDebug() << filePath;
    emit svgSignal(filePath);
    return filePath;
}