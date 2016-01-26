TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    Background.cpp \
    utils.cpp \
    button.cpp \
    pokedex.cpp \
    levelbar.cpp \
    berry.cpp \
    slot.cpp \
    pokemon.cpp

HEADERS += \
    Background.h \
    utils.h \
    button.h \
    pokedex.h \
    levelbar.h \
    berry.h \
    slot.h \
    pokemon.h

