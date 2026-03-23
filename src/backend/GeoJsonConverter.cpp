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

void GeoJsonConverter::convertFile()
{
    std::string fileName = "resources/" + currentMap + "_" + currentProjection + ".svg";
	if (!checkFileExists(fileName)&&(!currentMap.empty())&&(!currentProjection.empty())) { // if cached svg file doesn't exist, create it
        std::ostringstream svgStream;
        svgStream << std::fixed << std::setprecision(7);

        svgStream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << 800 << "\" height=\"" << 800 << "\">\n";
        svgStream << "<rect width=\"" << 800 << "\" height=\"" << 800 << "\" fill=\"transparent\"/>\n";
        // should put height and width as constants

        json land = readFile("resources/ne_110m_land.json");
		json boundaries = readFile("resources/ne_110m_admin_0_boundary_lines_land.json");

        for (const auto& feature : land["features"]) {
            const auto& geometry = feature["geometry"];
            const auto& type = geometry["type"];

            if (type == "Polygon") {
                for (const auto& polygon : geometry["coordinates"]) {
                    svgStream << "<polygon points=\"";
                    for (const auto& point : polygon) {
                        Projections coordinates(point[0].get<double>(), point[1].get<double>());
						coordinates.applyProjection(currentProjection);
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
                            coordinates.applyProjection(currentProjection);
                            svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
                        }
                        svgStream << "\" fill=\"#4CAF50\" stroke=\"#333\" stroke-width=\"0.1\"/>\n";
                    }
                }
            }
        }
        for (const auto& feature : boundaries["features"]) {
            const auto& geometry = feature["geometry"];
            const auto& type = geometry["type"];

            if (type == "LineString") {
                svgStream << "<polyline points=\"";
                for (const auto& point : geometry["coordinates"]) {

                    Projections coordinates(point[0].get<double>(), point[1].get<double>());
                    coordinates.applyProjection(currentProjection);
                    svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
                }
                svgStream << "\" fill=\"none\" stroke=\"#333\" stroke-width=\"0.1\"/>\n";
            }
            else if (type == "MultiLineString") {
                for (const auto& multiline : geometry["coordinates"]) {
                    svgStream << "<polyline points=\"";
                    for (const auto& point : multiline) {

                        Projections coordinates(point[0].get<double>(), point[1].get<double>());
                        coordinates.applyProjection(currentProjection);
                        svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
                    }
                    svgStream << "\" fill=\"none\" stroke=\"#333\" stroke-width=\"0.1\"/>\n";
                }
            }
        }

        svgStream << "</svg>\n";
        std::ofstream svgFile(fileName);
        svgFile << svgStream.str();
        svgFile.close();
    }
    outputSVG();
}

void GeoJsonConverter::outputSVG()
{
    QString filePath = "file:///" + QFileInfo("resources/" + QString::fromStdString(currentMap) + "_" + QString::fromStdString(currentProjection) + ".svg").absoluteFilePath();
    qDebug() << filePath;
    emit svgSignal(filePath);
	emit projectionChanged(QString::fromStdString(currentProjection));
}

Q_INVOKABLE void GeoJsonConverter::selectProjection(const QString projection)
{
    currentProjection = projection.toStdString();
    convertFile();
}

Q_INVOKABLE void GeoJsonConverter::selectMap(const QString map)
{
	currentMap = map.toStdString();
	convertFile();
}