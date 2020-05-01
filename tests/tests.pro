QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testviewmodel.cpp \
    ../src/abstracthostinfo.cpp \
    ../src/viewmodel.cpp \
    mockhostinfo.cpp

HEADERS += \
    ../src/abstracthostinfo.h \
    ../src/viewmodel.h \
    mockhostinfo.h
