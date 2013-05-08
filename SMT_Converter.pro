#-------------------------------------------------
#
# Project created by QtCreator 2012-04-02T21:35:10
#
#-------------------------------------------------

QT       += core gui



TARGET = SMT_Converter
TEMPLATE = app

include(qt-solutions-qt-solutions/qtsingleapplication/src/qtsingleapplication.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    mygview.cpp \
    csvreader.cpp \
    csvimport.cpp \
    myelem.cpp \
    fnumber.cpp \
    groupedit.cpp \
    orderby.cpp \
    newpart.cpp \
    basicsettings.cpp \
    basicsettingsmodel.cpp \
    elements.cpp \
    settings.cpp \
    documentwidget.cpp \
    dialogmoverotate.cpp \
    groupsmodel.cpp \
    basicgroupsdialog.cpp \
    savetobinary.cpp \
    groupsaclmodel.cpp \
    addacldialog.cpp \
    groupsaclfilter.cpp \
    changegroupdialog.cpp

HEADERS  += mainwindow.h \
    mygview.h \
    csvreader.h \
    myelem.h \
    csvimport.h \
    fnumber.h \
    groupedit.h \
    orderby.h \
    newpart.h \
    basicsettings.h \
    basicsettingsmodel.h \
    elements.h \
    settings.h \
    documentwidget.h \
    dialogmoverotate.h \
    groupsmodel.h \
    basicgroupsdialog.h \
    savetobinary.h \
    groupsaclmodel.h \
    addacldialog.h \
    groupsaclfilter.h \
    changegroupdialog.h

FORMS    += mainwindow.ui \
    csvimport.ui \
    fnumber.ui \
    groupedit.ui \
    orderby.ui \
    newpart.ui \
    basicsettings.ui \
    dialogmoverotate.ui \
    basicgroupsdialog.ui \
    addacldialog.ui \
    changegroupdialog.ui
TRANSLATIONS += tablo_ru.ts
RESOURCES += icons.qrc
RC_FILE = icon.rc
