QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    ../src/abstractmpdconnection.cpp \
    ../src/abstractmpdsettings.cpp \
    ../src/abstractmpdsettingsfactory.cpp \
    ../src/presenter.cpp \
    mockmpdconnection.cpp \
    mockmpdsettings.cpp \
    mockmpdsettingsfactory.cpp \
    tst_testpresenter.cpp

HEADERS += \
    ../src/abstractmpdconnection.h \
    ../src/abstractmpdsettings.h \
    ../src/abstractmpdsettingsfactory.h \
    ../src/presenter.h \
    mockmpdconnection.h \
    mockmpdsettings.h \
    mockmpdsettingsfactory.h
