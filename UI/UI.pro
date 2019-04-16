#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T07:40:08
#
#-------------------------------------------------

QT       += core gui multimedia

QT += 3dcore 3drender 3dinput 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
    token.cpp \
    main.cpp \
    resources_ui.cpp \
    base_ui.cpp \
    mainwindow.cpp \
    player_selection.cpp \
    Start_page.cpp \
    musiccontrols.cpp \
    cube_ui.cpp \
    map.cpp \
    ../core/Board.cpp \
    ../core/BuyableField.cpp \
    ../core/Company.cpp \
    ../core/Field.cpp \
    ../core/GameManager.cpp \
    ../core/player.cpp
#    ../core/Company.cpp \

HEADERS += \
    token.h \
    resources_ui.h \
    base_ui.h \
    mainwindow.h \
    player_selection.h \
    Start_page.h \
    musiccontrols.h \
    cube_ui.h \
    map.h \
    ../core/Board.h \
    ../core/BuyableField.h \
    ../core/Company.h \
    ../core/Field.h \
    ../core/GameManager.h \
    ../core/player.h
#    ../core/BaseField.h \

INCLUDEPATH += "/media/ghostfox/NewVolume/projects/QT/wows/"
FORMS += \
    mainwindow.ui \
    player_selection.ui \
    Start_page.ui \
    musiccontrols.ui \
    cube_ui.ui \
    map.ui \
    token.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    k.qrc \
    logo.qrc

DISTFILES += \
    ../core/README.md
