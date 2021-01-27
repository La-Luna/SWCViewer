#-------------------------------------------------
#
# Project created by QtCreator 2020-11-05T16:55:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gl_opengl_swcviewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    shader.cpp \
    rendersoma.cpp \
    renderneurite.cpp \
    resourcemanager.cpp \
    rwidget.cpp \
    mainwindow.cpp \
    object.cpp \
    lunacylender.cpp \
    lunamatrix.cpp \
    vec3.cpp \
    neurogeometry.cpp \
    global.cpp \
    swcfiledata.cpp

HEADERS += \
    shader.h \
    include/neurogeometry.h \
    include/neuropoint.h \
    include/swcfiledata.h \
    include/vec3.h \
    rendersoma.h \
    renderneurite.h \
    resourcemanager.h \
    rwidget.h \
    mainwindow.h \
    object.h \
    lunacylender.h \
    lunamatrix.h \
    global.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    shader.qrc \
    swc.qrc

DISTFILES += \
    test2.swc
