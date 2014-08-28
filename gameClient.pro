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
    mytcpsocket.cpp \
    loginlauncher.cpp \
    downloadlauncher.cpp \
    mainmenu.cpp

HEADERS  += mainwindow.h \
    mytcpsocket.h \
    loginlauncher.h \
    downloadlauncher.h \
    includeFile.h \
    mainmenu.h

FORMS    += mainwindow.ui \
    loginlauncher.ui \
    downloadlauncher.ui \
    mainmenu.ui
