QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    ../src/abstracthostinfo.cpp \
    ../src/abstractmpdsettings.cpp \
    ../src/abstractmpdsettingsfactory.cpp \
    ../src/controller.cpp \
    mockhostinfo.cpp \
    mockmpdsettings.cpp \
    mockmpdsettingsfactory.cpp \
    tst_testcontroller.cpp

HEADERS += \
    ../src/abstracthostinfo.h \
    ../src/abstractmpdsettings.h \
    ../src/abstractmpdsettingsfactory.h \
    ../src/controller.h \
    mockhostinfo.h \
    mockmpdsettings.h \
    mockmpdsettingsfactory.h
