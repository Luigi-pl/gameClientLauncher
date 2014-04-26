#-------------------------------------------------
#
# Project created by QtCreator 2014-04-26T13:12:01
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gameClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindow2.cpp \
    mytcpsocket.cpp

HEADERS  += mainwindow.h \
    mainwindow2.h \
    mytcpsocket.h

FORMS    += mainwindow.ui \
    mainwindow2.ui
