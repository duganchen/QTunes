QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testcontroller.cpp \
    ../src/controller.cpp

HEADERS += \
    ../src/controller.h
