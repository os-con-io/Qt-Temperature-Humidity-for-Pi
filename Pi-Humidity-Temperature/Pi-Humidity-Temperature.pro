#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T10:05:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pi-Humidity-Temperature
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    read.h

FORMS    += mainwindow.ui

LIBS+= -lwiringPi -L/usr/local/qwt-6.0.2/lib -lqwt

INCLUDEPATH= -I/usr/local/qwt-6.0.2/include
