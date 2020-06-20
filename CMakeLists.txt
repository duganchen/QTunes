cmake_minimum_required(VERSION 3.13)
project(qt_mpd_client_demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 5.15 COMPONENTS QuickControls2 Core Quick Network Test REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBMPDCLIENT REQUIRED IMPORTED_TARGET libmpdclient)

add_subdirectory(Controller)
add_subdirectory(QTunes)
enable_testing()
add_subdirectory(tests)

target_include_directories(qtunes PRIVATE ${LIBMPDCLIENT_INCLUDE_DIRS})

target_compile_definitions(qtunes
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(qtunes
  PRIVATE Qt5::QuickControls2 Qt5::Core Qt5::Network Qt5::Quick PkgConfig::LIBMPDCLIENT)
