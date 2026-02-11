cmake_minimum_required(VERSION 3.16)
project(projection_map LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

find_package(Qt6 COMPONENTS Core Gui Qml REQUIRED)

qt_add_executable(projection_map WIN32 MACOSX_BUNDLE
    "src/main.cpp"
    "src/backend/GeoJsonConverter.cpp" 
    "src/backend/GeoJsonConverter.h"
    "src/backend/Projections.cpp"
    "src/backend/Projections.h"
)

target_link_libraries(projection_map PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    nlohmann_json::nlohmann_json
)

# Resources:
set(qml_resource_files
    "src/gui/qml/main.qml"
)

file(COPY ${PROJECT_SOURCE_DIR}/src/resources  DESTINATION ${PROJECT_BINARY_DIR} ) 

qt6_add_resources(projection_map "qml"
    PREFIX
        "/"
    FILES
        ${qml_resource_files}
)
