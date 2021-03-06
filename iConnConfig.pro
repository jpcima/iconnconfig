#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T21:28:32
#
#-------------------------------------------------

DISTFILES = .astylerc

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iConnConfig
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# RTMidi defines
unix:!macx: DEFINES += __LINUX_ALSA__
macx: DEFINES += __MACOSX_CORE__
win32: DEFINES += __WINDOWS_MM__

DEFINES += __MIO_DEBUG__

DEFINES += __RTMIDI_DEBUG__
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS = tr/iconnconfig_de_DE.ts \
               tr/iconnconfig_fr_FR.ts

SOURCES +=\
        src/RtMidi.cpp \
    src/main.cpp \
    src/device.cpp \
    src/sysex/midi.cpp \
    src/devicedetection.cpp \
    src/config/configuration.cpp \
    src/devicedetectionprocessor.cpp \
    src/sysex/sysexmessage.cpp \
    src/deviceselectiontablemodel.cpp \
    src/widgets/portsettingwidget.cpp \
    src/widgets/deviceinfowidget.cpp \
    src/widgets/portswidget.cpp \
    src/widgets/multiinfowidget.cpp \
    src/widgets/centralwidget.cpp \
    src/sysex/getinfolist.cpp \
    src/widgets/infotablewidget.cpp \
    src/sysex/retsetinfo.cpp \
    src/sysex/getinfo.cpp \
    src/sysex/retcommandlist.cpp \
    src/sysex/getdevice.cpp \
    src/sysex/retinfolist.cpp \
    src/sysex/getcommandlist.cpp \
    src/sysex/ack.cpp \
    src/sysex/getethernetportinfo.cpp \
    src/widgets/ethernetinfowidget.cpp \
    src/sysex/retsetethernetportinfo.cpp \
    src/sysex/getmidiinfo.cpp \
    src/sysex/retsetmidiportinfo.cpp \
    src/sysex/retsetmidiinfo.cpp \
    src/widgets/multiinfolistentry.cpp \
    src/widgets/controls/portbutton.cpp \
    src/widgets/portroutingwidget.cpp \
    src/sysex/getmidiportinfo.cpp \
    src/sysex/getmidiportroute.cpp \
    src/sysex/retsetmidiportroute.cpp \
    src/sysex/saverestore.cpp \
    src/sysex/getsaverestorelist.cpp \
    src/sysex/retsaverestorelist.cpp \
    src/widgets/controls/ipaddressinput.cpp \
    src/sysex/communicationexception.cpp \
    src/sysex/protocolexception.cpp \
    src/aboutdialog.cpp \
    src/iconnconfigmain.cpp \
    src/sysex/getgizmocount.cpp \
    src/sysex/retgizmocount.cpp

INCLUDEPATH += /usr/include/libusb-1.0/

HEADERS  += \
    src/RtMidi.h \
    src/device.h \
    src/sysex/midi.h \
    src/devicedetection.h \
    src/config/configuration.h \
    src/devicedetectionprocessor.h \
    src/sysex/sysexmessage.h \
    src/deviceselectiontablemodel.h \
    src/events/events.h \
    src/device.h \
    src/widgets/portsettingwidget.h \
    src/widgets/deviceinfowidget.h \
    src/widgets/portswidget.h \
    src/widgets/multiinfowidget.h \
    src/widgets/centralwidget.h \
    src/sysex/getinfolist.h \
    src/widgets/infotablewidget.h \
    src/sysex/retsetinfo.h \
    src/sysex/getinfo.h \
    src/sysex/retcommandlist.h \
    src/sysex/getdevice.h \
    src/sysex/retinfolist.h \
    src/sysex/getcommandlist.h \
    src/sysex/ack.h \
    src/sysex/getethernetportinfo.h \
    src/widgets/ethernetinfowidget.h \
    src/sysex/retsetethernetportinfo.h \
    src/sysex/getmidiinfo.h \
    src/sysex/retsetmidiportinfo.h \
    src/sysex/retsetmidiinfo.h \
    src/widgets/multiinfolistentry.h \
    src/widgets/controls/portbutton.h \
    src/widgets/portroutingwidget.h \
    src/sysex/getmidiportinfo.h \
    src/widgets/portdisplayhelper.h \
    src/sysex/getmidiportroute.h \
    src/sysex/retsetmidiportroute.h \
    src/sysex/saverestore.h \
    src/sysex/getsaverestorelist.h \
    src/sysex/retsaverestorelist.h \
    src/widgets/controls/ipaddressinput.h \
    src/sysex/communicationexception.h \
    src/sysex/protocolexception.h \
    src/config/qsettings-xml.h \
    src/definitions.h \
    src/aboutdialog.h \
    src/iconnconfigmain.h \
    src/sysex/getgizmocount.h \
    src/sysex/retgizmocount.h

FORMS    += \
    src/devicedetection.ui \
    src/widgets/multiinfowidget.ui \
    src/aboutdialog.ui \
    src/iconnconfigmain.ui

unix:!macx: LIBS += -lasound \
                    -lpthread \
                    -lusb-1.0

RESOURCES += \
    translations.qrc \
    resources.qrc

DISTFILES += \
    README.md \
    RELEASENOTES.md \
    BUILD.md \
    tr/iconnconfig_de_DE.ts \
    tr/iconnconfig_de_DE.qm \
    tr/iconnconfig_fr_FR.ts \
    tr/iconnconfig_fr_FR.qm \
    .astylerc
