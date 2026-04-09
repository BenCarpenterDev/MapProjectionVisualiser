cmake_minimum_required(VERSION 3.16)
project(MapProjectionVisualiser LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(json)
find_package(Qt6 COMPONENTS Core Gui Qml REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories("src/backend")
add_subdirectory("src/backend")

target_link_libraries(MapProjectionLibrary  PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    nlohmann_json::nlohmann_json
)

qt_add_executable(MapProjectionVisualiser WIN32 MACOSX_BUNDLE
    "src/main.cpp"
)
set_target_properties(MapProjectionVisualiser PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
target_link_libraries(MapProjectionVisualiser  PUBLIC
    MapProjectionLibrary
)

add_executable (MapProjectionVisualiserTest
    "src/tests/unit/MainTests.cpp"
    "src/tests/unit/ProjectionsTests.cpp"
    "src/tests/unit/GeoJsonTests.cpp"
)

target_link_libraries(MapProjectionVisualiserTest PRIVATE
    MapProjectionLibrary
    Boost::unit_test_framework
)

target_compile_definitions(MapProjectionVisualiserTest PRIVATE
    TEST_RESOURCES_DIR="${CMAKE_CURRENT_SOURCE_DIR}/src/tests/unit/comparision"
)

# Resources:
set(qml_resource_files
    "src/gui/MainView.qml"
    "src/gui/OptionsButtons.qml"
    "src/gui/ProjectionsPanel.qml"
    "src/gui/InfoPanel.qml"
    "src/gui/InfoButton.qml"
    "src/gui/InfoContent.qml"
    "src/gui/MapPanel.qml"
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