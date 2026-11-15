cmake_minimum_required(VERSION 3.16)
project(MapProjectionVisualiser LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Clang Tidy
#set(CMAKE_CXX_CLANG_TIDY
#    clang-tidy;
#    -header-filter='src/backend/.*';)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

# Using FetchContent to include Nlohmann Json
include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(json)
# Finding Qt and Boost
find_package(Qt6 COMPONENTS Core Gui Qml QuickTest REQUIRED)
find_package(Boost CONFIG REQUIRED COMPONENTS unit_test_framework REQUIRED)

# Using backend scripts as a library to be linked to the visualiser and tests
include_directories("src/backend")
add_subdirectory("src/backend")

target_link_libraries(MapProjectionLibrary  PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    nlohmann_json::nlohmann_json
)

# Main Executable
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

# C++ Unit Tests Executable
add_executable (LibraryTest
    "src/tests/boost/mainBoostTests.cpp"
    "src/tests/boost/ProjectionsTests.cpp"
    "src/tests/boost/GeoJsonTests.cpp"
)

target_link_libraries(LibraryTest PRIVATE
    MapProjectionLibrary
    Boost::unit_test_framework
)

target_compile_definitions(LibraryTest PRIVATE
    TEST_RESOURCES_DIR="${CMAKE_CURRENT_SOURCE_DIR}/src/tests/boost/comparision"
)

set_target_properties(LibraryTest PROPERTIES
    CXX_CLANG_TIDY ""
)

# QML Unit Tests Executable
add_executable(UserInterfaceTest 
    "src/tests/qtquick/mainQuickTests.cpp"
)

target_link_libraries(UserInterfaceTest PRIVATE
    MapProjectionLibrary
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::QuickTest
)

target_compile_definitions(UserInterfaceTest PRIVATE
    -DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/src/tests/qtquick"
)

set_target_properties(UserInterfaceTest PROPERTIES
    CXX_CLANG_TIDY ""
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

# Copying required resources to the build directory for both the visualiser and tests
file(COPY ${PROJECT_SOURCE_DIR}/src/resources/  DESTINATION ${PROJECT_BINARY_DIR}/resources )

qt6_add_resources(MapProjectionVisualiser  "qml"
    PREFIX
        "/"
    FILES
        ${qml_resource_files}
)

qt6_add_resources(UserInterfaceTest   "qml"
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