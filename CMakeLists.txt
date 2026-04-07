cmake_minimum_required(VERSION 3.16)
project(MapProjectionVisualiser LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(FetchContent)
FetchContent_Declare(
    json 
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(json)

find_package(Qt6 COMPONENTS Core Gui Qml REQUIRED)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

qt_add_executable(MapProjectionVisualiser WIN32 MACOSX_BUNDLE
    "src/main.cpp"
    "src/backend/GeoJsonConverter.cpp" 
    "src/backend/GeoJsonConverter.h"
    "src/backend/Projections.cpp"
    "src/backend/Projections.h"
)

set_target_properties(MapProjectionVisualiser PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(MapProjectionVisualiser  PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    nlohmann_json::nlohmann_json
)

add_executable (MapProjectionVisualiserTest
    "src/tests/unit/projectionsTest.cpp"
    "src/backend/GeoJsonConverter.cpp" 
    "src/backend/GeoJsonConverter.h"
    "src/backend/Projections.cpp"
    "src/backend/Projections.h"
)

target_link_libraries(MapProjectionVisualiserTest PRIVATE
    Boost::unit_test_framework
    Qt::Core
    Qt::Gui
    Qt::Qml
    nlohmann_json::nlohmann_json
)

# Resources:
set(qml_resource_files
    "src/gui/qml/MainView.qml"
    "src/gui/qml/OptionsButtons.qml"
    "src/gui/qml/ProjectionsPanel.qml"
    "src/gui/qml/InfoPanel.qml"
    "src/gui/qml/InfoButton.qml"
    "src/gui/qml/InfoContent.qml"
    "src/gui/qml/MapPanel.qml"
)

file(COPY ${PROJECT_SOURCE_DIR}/src/resources/additional/pangaea.json  DESTINATION ${PROJECT_BINARY_DIR}/resources )
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/additional/shape1.json  DESTINATION ${PROJECT_BINARY_DIR}/resources )
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/additional/shape2.json  DESTINATION ${PROJECT_BINARY_DIR}/resources )
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/additional/shape3.json  DESTINATION ${PROJECT_BINARY_DIR}/resources )
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/additional/shape4.json  DESTINATION ${PROJECT_BINARY_DIR}/resources )

file(COPY ${PROJECT_SOURCE_DIR}/src/resources/natural-earth/geojson/ne_110m_land.geojson  DESTINATION ${PROJECT_BINARY_DIR}/resources ) 
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/natural-earth/geojson/ne_110m_admin_0_boundary_lines_land.geojson  DESTINATION ${PROJECT_BINARY_DIR}/resources ) 
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/natural-earth/geojson/ne_110m_graticules_10.geojson  DESTINATION ${PROJECT_BINARY_DIR}/resources ) 
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/natural-earth/geojson/ne_110m_wgs84_bounding_box.geojson  DESTINATION ${PROJECT_BINARY_DIR}/resources ) 
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/natural-earth/geojson/ne_110m_lakes.geojson  DESTINATION ${PROJECT_BINARY_DIR}/resources ) 
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/natural-earth/geojson/ne_110m_rivers_lake_centerlines.geojson  DESTINATION ${PROJECT_BINARY_DIR}/resources ) 

qt6_add_resources(MapProjectionVisualiser  "qml"
    PREFIX
        "/"
    FILES
        ${qml_resource_files}
)

install(TARGETS MapProjectionVisualiser
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)