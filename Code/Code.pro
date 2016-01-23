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
    gameengine.cpp \
    pokemon.cpp \
    berry.cpp

HEADERS += \
    Background.h \
    utils.h \
    button.h \
    pokedex.h \
    levelbar.h \
    gameengine.h \
    pokemon.h \
    berry.h

