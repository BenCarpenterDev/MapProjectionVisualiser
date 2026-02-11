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

Q_INVOKABLE void GeoJsonConverter::convertFile()
{
    std::ostringstream svgStream;
    svgStream << std::fixed << std::setprecision(7);

    svgStream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << 800 << "\" height=\"" << 800 << "\">\n";
    svgStream << "<rect width=\"" << 800 << "\" height=\"" << 800 << "\" fill=\"white\"/>\n"; 
    // should put height and width as constants

    json geoJson = readFile("resources/ne_50m_land.json");

    for (const auto& feature : geoJson["features"]) {
        const auto& geometry = feature["geometry"];
        const auto& type = geometry["type"];

        if (type == "Polygon") {
            for (const auto& polygon : geometry["coordinates"]) {
                svgStream << "<polygon points=\"";
                for (const auto& point : polygon) {
                    Projections coordinates(point[0].get<double>(), point[1].get<double>());

                    //coordinates.wgs84();
					coordinates.webMercator();
                    svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
                }
                svgStream << "\" />\n";
            }
        }
        else if (type == "MultiPolygon") {
            for (const auto& multipolygon : geometry["coordinates"]) {
                for (const auto& polygon : multipolygon) {
                    svgStream << "<polygon points=\"";
                    for (const auto& point : polygon) {
                        Projections coordinates(point[0].get<double>(), point[1].get<double>());

                        coordinates.wgs84();
                        //coordinates.webMercator();
                        svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
                    }
                    svgStream << " Z\" />\n";
                }
            }
        }
    }

    svgStream << "</svg>\n";
    std::ofstream svgFile("resources/output.svg");
    svgFile << svgStream.str();
    svgFile.close();
	outputSVG();
}

Q_INVOKABLE QString GeoJsonConverter::outputSVG()
{
    QString filePath = "file:///" + QFileInfo("resources/output.svg").absoluteFilePath();
    qDebug() << filePath;
    emit svgSignal(filePath);
    return filePath;
}