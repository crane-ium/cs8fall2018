TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    runway_controls.cpp \
    airplane.cpp \
    vehicle.cpp

HEADERS += \
    runway_controls.h \
    airplane.h \
    vehicle.h
