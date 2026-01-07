#ifndef GEOJSONCONVERTER_H
#define GEOJSONCONVERTER_H

#include <QObject>
#include <QString>

#include <nlohmann/json.hpp>

class GeoJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit GeoJsonConverter(QObject *parent = nullptr);

    nlohmann::json readFile(const std::string path);

    void convertFile();
};

#endif // GEOJSONCONVERTER_H