project(MapProjection)

set(HEADER_FILES
    Projections.h
    GeoJsonConverter.h
)

set(SOURCE_FILES
    Projections.cpp
    GeoJsonConverter.cpp
)

add_library(MapProjectionLibrary STATIC ${SOURCE_FILES} ${HEADER_FILES})