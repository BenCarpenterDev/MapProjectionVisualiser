#include "GeoJsonConverter.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QStringBuilder>
#include <limits>
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>>

using json = nlohmann::json;

GeoJsonConverter::GeoJsonConverter(QObject *parent) : QObject(parent)
{
}

void GeoJsonConverter::convertFile()
{
    qDebug() << "Current directory:" << QDir::currentPath();
    
    std::ifstream file("ne_110m_land.json");
    json geoJson = json::parse(file);

    for (const auto& feature : geoJson["features"]) {
        const auto& geometry = feature["geometry"];
        const auto& type = geometry["type"];

        if (type == "Polygon") {
            for (const auto& polygon : geometry["coordinates"]) {
                for (const auto& point : polygon) {
                    std::cout << std::setprecision(7) << point[0].get<double>() << ", ";
                    std::cout << std::setprecision(7) << point[1].get<double>() << "\n";
                }
            }
        }
        else if (type == "MultiPolygon") {
            for (const auto& multipolygon : geometry["coordinates"]) {
                for (const auto& polygon : multipolygon) {
                    for (const auto& point : polygon) {
                        std::cout << std::setprecision(7) << point[0].get<double>() << ", ";
                        std::cout << std::setprecision(7) << point[1].get<double>() << "\n";
                    }
                }
            }
        }
    }
}

int main() {
	GeoJsonConverter converter;
	converter.convertFile();
    return 0;
}