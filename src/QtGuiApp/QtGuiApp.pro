#-------------------------------------------------
#
# Project created by QtCreator 2022-01-17T22:18:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtGuiApp
TEMPLATE = app


SOURCES += main.cpp\
    guimain.cpp \
    guimessagebox.cpp \
    utils.cpp

HEADERS  += \
    guimain.h \
    guimessagebox.h \
    iconhelper.h \
    utils.h

FORMS    += \
    guimain.ui \
    guimessagebox.ui

RESOURCES += \
    rc.qrc

DISTFILES +=
