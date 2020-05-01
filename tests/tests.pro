QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    ../src/abstracthostinfo.cpp \
    ../src/controller.cpp \
    mockhostinfo.cpp \
    tst_testcontroller.cpp

HEADERS += \
    ../src/abstracthostinfo.h \
    ../src/controller.h \
    mockhostinfo.h
