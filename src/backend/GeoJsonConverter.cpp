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

GeoJsonConverter::GeoJsonConverter(QObject *parent) : QObject(parent)
{
}

nlohmann::json GeoJsonConverter::readFile(const std::string path)
{
    std::ifstream file(path);
    nlohmann::json geoJson = nlohmann::json::parse(file);
    return geoJson;
}

bool GeoJsonConverter::checkFileExists(const std::string path) {
    std::ifstream file(path);
	return file.good();
}

void GeoJsonConverter::svgContentFormat(std::ostringstream& svgStream, nlohmann::json jsonFile, std::string fillColour, std::string strokeColour) {
    for (const auto& feature : jsonFile["features"]) {
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
                svgStream << "\" fill=\""+fillColour+"\" stroke=\""+strokeColour+"\" stroke-width=\"0.3\"/>\n";
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
                    svgStream << "\" fill=\"" + fillColour + "\" stroke=\"" + strokeColour + "\" stroke-width=\"0.3\"/>\n";
                }
            }
        }
        else if (type == "LineString") {
            svgStream << "<polyline points=\"";
            for (const auto& point : geometry["coordinates"]) {

                Projections coordinates(point[0].get<double>(), point[1].get<double>());
                coordinates.applyProjection(currentProjection);
                svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
            }
            svgStream << "\" fill=\"" + fillColour + "\" stroke=\"" + strokeColour + "\" stroke-width=\"0.3\"/>\n";
        }
        else if (type == "MultiLineString") {
            for (const auto& multiline : geometry["coordinates"]) {
                svgStream << "<polyline points=\"";
                for (const auto& point : multiline) {

                    Projections coordinates(point[0].get<double>(), point[1].get<double>());
                    coordinates.applyProjection(currentProjection);
                    svgStream << " " << coordinates.projectedX << "," << coordinates.projectedY;
                }
                svgStream << "\" fill=\"" + fillColour + "\" stroke=\"" + strokeColour + "\" stroke-width=\"0.3\"/>\n";
            }
        }
    }
}

void GeoJsonConverter::convertFile(std::string selectedMap)
{
    std::string fileName = "resources/" + selectedMap + "_" + currentProjection + ".svg";
    if (!checkFileExists(fileName) && (!selectedMap.empty()) && (!currentProjection.empty())) { // if cached svg file doesn't exist, create it
        std::ostringstream svgStream;
        svgStream << std::fixed << std::setprecision(7);

        svgStream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << 800 << "\" height=\"" << 800 << "\">\n";
        svgStream << "<rect width=\"" << 800 << "\" height=\"" << 800 << "\" fill=\"transparent\"/>\n";
        // should put height and width as constants

        if (selectedMap =="worldMap")
        {
            nlohmann::json land = readFile("resources/ne_110m_land.geojson");
            nlohmann::json boundaries = readFile("resources/ne_110m_admin_0_boundary_lines_land.geojson");
            nlohmann::json lakes = readFile("resources/ne_110m_lakes.geojson");
            nlohmann::json lakeCenterlines = readFile("resources/ne_110m_rivers_lake_centerlines.geojson");

            svgContentFormat(svgStream, land, "#4CAF50", "#333");
            svgContentFormat(svgStream, boundaries, "none", "#333");
			svgContentFormat(svgStream, lakes, "#72AFED", "#72AFED");
            svgContentFormat(svgStream, lakeCenterlines, "none", "#72AFED");
        }
        else if (selectedMap == "gridMap")
        {
            nlohmann::json grid = readFile("resources/ne_110m_graticules_10.geojson");
            nlohmann::json boundingBox = readFile("resources/ne_110m_wgs84_bounding_box.geojson");
            svgContentFormat(svgStream, grid, "none", "#333");
            svgContentFormat(svgStream, boundingBox, "none", "#333");
        }
        else if (selectedMap == "preHistoricMap")
        {
            nlohmann::json historicLand = readFile("resources/pangaea.json");
            svgContentFormat(svgStream, historicLand, "#4CAF50", "#333");
        }
        else if (selectedMap =="shapesMap")
        {
            svgContentFormat(svgStream, readFile("resources/shape1.json"), "red", "#333");
            svgContentFormat(svgStream, readFile("resources/shape2.json"), "blue", "#333");
            svgContentFormat(svgStream, readFile("resources/shape3.json"), "green", "#333");
            svgContentFormat(svgStream, readFile("resources/shape4.json"), "yellow", "#333");
		}
        else if (selectedMap == "marsMap")
        {
            svgContentFormat(svgStream, readFile("resources/opm_499_mars_albedo_tes_7classes.geojson"), "#8c7bbf", "#ffffff");
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
    emit mapChanged(filePath);
	emit projectionChanged(QString::fromStdString(currentProjection));
}

Q_INVOKABLE void GeoJsonConverter::selectProjection(const QString projection)
{
    currentProjection = projection.toStdString();
    convertFile(currentMap);
    convertFile("gridMap");
    QString filePath = "file:///" + QFileInfo("resources/gridMap_" + QString::fromStdString(currentProjection) + ".svg").absoluteFilePath();
    emit gridChanged(filePath);
}

Q_INVOKABLE void GeoJsonConverter::selectMap(const QString map)
{
	currentMap = map.toStdString();
	convertFile(currentMap);
}