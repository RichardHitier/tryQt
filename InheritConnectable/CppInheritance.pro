QT       += core gui
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    er.cpp \
    fm.cpp \
    mainwindow.cpp \
    abstractlistener.cpp

HEADERS += \
    er.h \
    fm.h \
    mainwindow.h \
    abstractlistener.h

FORMS += \
    mainwindow.ui

