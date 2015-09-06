TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    httprequest.cpp \
    qftp.cpp \
    qurlinfo.cpp \
    ftprequest.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    httprequest.h \
    qftp_p.h \
    qobject_p.h \
    qurlinfo_p.h \
    ftprequest.h
