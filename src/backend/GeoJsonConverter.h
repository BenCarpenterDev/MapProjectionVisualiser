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

    Q_INVOKABLE void convertFile(const QString projection);
    Q_INVOKABLE QString outputSVG(const QString projection);

signals:
    void svgSignal(const QString& filePath);
};

#endif // GEOJSONCONVERTER_H