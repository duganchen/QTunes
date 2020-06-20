set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

add_executable(
    qtunes
    panemodel.cpp
    qtunes.cpp
    qml.qrc
)

target_include_directories(qtunes PRIVATE "../Controller" ${LIBMPDCLIENT_INCLUDE_DIRS})

target_compile_definitions(qtunes
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(qtunes
  PRIVATE Controller Qt5::QuickControls2 Qt5::Core Qt5::Network Qt5::Quick PkgConfig::LIBMPDCLIENT)
