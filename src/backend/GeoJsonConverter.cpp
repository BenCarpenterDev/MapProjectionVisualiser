#include "GeoJsonConverter.h"
#include "Projections.h"

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

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

void GeoJsonConverter::convertFile()
{
    std::ostringstream svgStream;
    svgStream << std::fixed << std::setprecision(7);

    svgStream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << 800 << "\" height=\"" << 800 << "\">\n";
    svgStream << "<rect width=\"" << 800 << "\" height=\"" << 800 << "\" fill=\"white\"/>\n";

    json geoJson = readFile("ne_110m_land.json");

    for (const auto& feature : geoJson["features"]) {
        const auto& geometry = feature["geometry"];
        const auto& type = geometry["type"];

        if (type == "Polygon") {
            for (const auto& polygon : geometry["coordinates"]) {
                svgStream << "<polygon points=\"";
                bool firstPoint = true;
                for (const auto& point : polygon) {
                    double x = point[0].get<double>();
                    double y = point[1].get<double>();

                    svgStream << " " << (x + 180.00) << "," << (y + 90);
                }
                svgStream << "\"/>\n";
            }
        }
        else if (type == "MultiPolygon") {
            for (const auto& multipolygon : geometry["coordinates"]) {
                for (const auto& polygon : multipolygon) {
                    svgStream << "<polygon points=\"";
                    bool firstPoint = true;
                    for (const auto& point : polygon) {
                        double x = point[0].get<double>();
                        double y = point[1].get<double>();

                        svgStream << " " << (x + 180.00) << "," << (y + 90);
                    }
                    svgStream << " Z\"/>\n";
                }
            }
        }
    }

    svgStream << "</svg>\n";
    std::ofstream svgFile("output.svg");
    svgFile << svgStream.str();
    svgFile.close();
}

int main() {
	GeoJsonConverter converter;
	converter.convertFile();
    return 0;
}