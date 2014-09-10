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
        ui/ui_source/mainwindow.cpp \
    mytcpsocket.cpp \
    ui/ui_source/loginlauncher.cpp \
    ui/ui_source/downloadlauncher.cpp \
    ui/ui_source/mainmenu.cpp \
    ui/ui_source/researchanddevelopment.cpp \
    ui/ui_source/fleetsadmirals.cpp \
    ui/ui_source/gamesettings.cpp \
    ui/ui_source/gamestatistics.cpp \
    ui/ui_source/battleground.cpp \
    data/datastorage.cpp \
    object/ship.cpp \
    data/gameobjectdata.cpp \
    data/equipmentdata.cpp \
    data/offensivedata.cpp \
    data/defensivedata.cpp \
    data/accuracymodifierdata.cpp \
    data/shipdata.cpp \
    object/gamerresearch.cpp \
    data/researchcategorydata.cpp \
    data/researchdata.cpp \
    sha512.cpp \
    object/gamer.cpp

HEADERS  += ui/ui_header/mainwindow.h \
    mytcpsocket.h \
    ui/ui_header/loginlauncher.h \
    ui/ui_header/downloadlauncher.h \
    includeFile.h \
    ui/ui_header/mainmenu.h \
    ui/ui_header/researchanddevelopment.h \
    ui/ui_header/fleetsadmirals.h \
    ui/ui_header/gamesettings.h \
    ui/ui_header/gamestatistics.h \
    ui/ui_header/battleground.h \
    data/datastorage.h \
    object/ship.h \
    data/gameobjectdata.h \
    data/equipmentdata.h \
    data/offensivedata.h \
    data/defensivedata.h \
    data/accuracymodifierdata.h \
    data/shipdata.h \
    object/gamerresearch.h \
    data/researchcategorydata.h \
    data/researchdata.h \
    sha512.h \
    object/gamer.h

FORMS    += ui/ui_gui/mainwindow.ui \
    ui/ui_gui/loginlauncher.ui \
    ui/ui_gui/downloadlauncher.ui \
    ui/ui_gui/mainmenu.ui \
    ui/ui_gui/researchanddevelopment.ui \
    ui/ui_gui/fleetsadmirals.ui \
    ui/ui_gui/gamesettings.ui \
    ui/ui_gui/gamestatistics.ui \
    ui/ui_gui/battleground.ui

OTHER_FILES += \
    sha512-license.txt
