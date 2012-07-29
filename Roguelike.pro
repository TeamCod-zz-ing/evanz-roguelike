#-------------------------------------------------
#
# Project created by QtCreator 2012-07-29T16:27:52
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Roguelike
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    world.cpp

HEADERS += \
    world.h

LIBS += -lpdcurses

