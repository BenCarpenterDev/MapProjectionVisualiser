#include "GeoJsonConverter.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QStringBuilder>
#include <limits>
#include <nlohmann/json.hpp>

#include <iostream>

using json = nlohmann::json;

GeoJsonConverter::GeoJsonConverter(QObject *parent) : QObject(parent)
{
}

void GeoJsonConverter::convertFile()
{
    qDebug() << "Current directory:" << QDir::currentPath();
    const QString path = "ne_110m_land.json"; // read file
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open GeoJSON file:" << path;
    }

    QTextStream in(&file);
    const QString contents = in.readAll(); // copy contents
    file.close();

    //json geoJson;
    //geoJson = json::parse(contents); // use nlohmann::json

    std::cout << "JSON File Contents:\n" << contents.toStdString() << std::endl;

}

int main() {
	GeoJsonConverter converter;
	converter.convertFile();
    return 0;
}