#ifndef GEOJSONCONVERTER_H
#define GEOJSONCONVERTER_H

#include <QObject>
#include <QString>

class GeoJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit GeoJsonConverter(QObject *parent = nullptr);

    void convertFile();
};

#endif // GEOJSONCONVERTER_H