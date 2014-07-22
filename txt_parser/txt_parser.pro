TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    txt_parse.cpp \
    sites.C

HEADERS += \
    txt_parse.h \
    sites.h

QMAKE_CXXFLAGS += -std=c++11

