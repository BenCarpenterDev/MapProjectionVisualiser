cmake_minimum_required(VERSION 3.16)
project(projection_map LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

find_package(Qt6 COMPONENTS Core Gui Qml Location REQUIRED)

qt_add_executable(projection_map WIN32 MACOSX_BUNDLE
    src/main.cpp
)

add_executable (ConvertTest 
    "src/backend/GeoJsonConverter.cpp" 
    "src/backend/GeoJsonConverter.h"
    "src/backend/Projections.cpp"
    "src/backend/Projections.h"
)

target_link_libraries(ConvertTest PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Location
    Qt::Qml
    nlohmann_json::nlohmann_json
)

target_link_libraries(projection_map PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Location
    Qt::Qml
)

# Resources:
set(qml_resource_files
    "src/gui/qml/main.qml"
    "src/resources/Europe.svg"
)

qt6_add_resources(projection_map "qml"
    PREFIX
        "/"
    FILES
        ${qml_resource_files}
)
