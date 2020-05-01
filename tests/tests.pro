QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testviewmodel.cpp \
    ../src/viewmodel.cpp

HEADERS += \
    ../src/viewmodel.h
