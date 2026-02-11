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

    Q_INVOKABLE void convertFile(const QString projection);
    Q_INVOKABLE QString outputSVG(const QString projection);

private:
    nlohmann::json readFile(const std::string path);

    bool checkFileExists(const std::string path);

signals:
    void svgSignal(const QString& filePath);
};

#endif // GEOJSONCONVERTER_H