cmake_minimum_required(VERSION 3.16)
project(projection_map LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Location)
find_package(Qt6 COMPONENTS Qml)

qt_add_executable(projection_map WIN32 MACOSX_BUNDLE
    source/main.cpp
)
target_link_libraries(projection_map PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Location
    Qt::Qml
)


# Resources:
set(qml_resource_files
    "qml/main.qml"
)

qt6_add_resources(projection_map "qml"
    PREFIX
        "/"
    FILES
        ${qml_resource_files}
)
