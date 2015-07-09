#-------------------------------------------------
#
# Project created by QtCreator 2015-07-06T18:06:36
#
#-------------------------------------------------

QT       += core gui
QT		 += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqltest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog/addmanagerdialog.cpp \
    dialog/deletedialog.cpp \
    dialog/inputbookcarddialog.cpp \
    dialog/inputbookiddialog.cpp \
    dialog/inputbookinformationdialog.cpp \
    dialog/logindialog.cpp \
    dialog/deletemanagerdialog.cpp \
    dialog/changemanagerinfodialog.cpp \
    dialog/searchdialog.cpp \
    dialog/searchreaderdialog.cpp \
    dialog/addreaderdialog.cpp \
    dialog/updatereaderdialog.cpp

HEADERS  += mainwindow.h \
    dialog/addmanagerdialog.h \
    dialog/deletedialog.h \
    dialog/inputbookcarddialog.h \
    dialog/inputbookiddialog.h \
    dialog/inputbookinformationdialog.h \
    dialog/logindialog.h \
    dialog/deletemanagerdialog.h \
    dialog/changemanagerinfodialog.h \
    dialog/searchdialog.h \
    dialog/searchreaderdialog.h \
    dialog/addreaderdialog.h \
    dialog/updatereaderdialog.h

FORMS    += mainwindow.ui \
    dialog/addmanagerdialog.ui \
    dialog/deletedialog.ui \
    dialog/inputbookcarddialog.ui \
    dialog/inputbookiddialog.ui \
    dialog/inputbookinformationdialog.ui \
    dialog/logindialog.ui \
    dialog/deletemanagerdialog.ui \
    dialog/changemanagerinfodialog.ui \
    dialog/searchdialog.ui \
    dialog/searchreaderdialog.ui \
    dialog/addreaderdialog.ui \
    dialog/updatereaderdialog.ui

RESOURCES += \
    resource.qrc
