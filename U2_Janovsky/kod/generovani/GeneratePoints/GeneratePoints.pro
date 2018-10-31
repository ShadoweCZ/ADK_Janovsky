#-------------------------------------------------
#
# Project created by QtCreator 2018-10-31T13:26:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeneratePoints
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    algorithms.cpp \
    draw.cpp

HEADERS  += widget.h \
    algorithms.h \
    draw.h

FORMS    += widget.ui
