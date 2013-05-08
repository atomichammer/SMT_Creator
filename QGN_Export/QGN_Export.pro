#-------------------------------------------------
#
# Project created by QtCreator 2013-03-29T16:08:15
#
#-------------------------------------------------

QT       -= gui

TARGET = QGN_Export
TEMPLATE = lib

DEFINES += QGN_EXPORT_LIBRARY

SOURCES += qgn_export.cpp \
    fnumber.cpp

HEADERS += qgn_export.h\
        QGN_Export_global.h \
    fnumber.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE7404553
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = QGN_Export.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    fnumber.ui
