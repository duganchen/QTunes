cmake_minimum_required(VERSION 3.6)

project(qtunes LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS QuickControls2 Core Quick Network REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(LIBMPDCLIENT REQUIRED IMPORTED_TARGET libmpdclient)

add_executable(
    qtunes
    albummodel.cpp
    artistmodel.cpp
    playlistmodel.cpp
    qtunes.cpp
    queuemodel.cpp
    songmodel.cpp
    qml.qrc
)

target_include_directories(qtunes PRIVATE ${LIBMPDCLIENT_INCLUDE_DIRS})

target_compile_definitions(qtunes
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(qtunes
  PRIVATE Qt5::QuickControls2 Qt5::Core Qt5::Network Qt5::Quick PkgConfig::LIBMPDCLIENT)
