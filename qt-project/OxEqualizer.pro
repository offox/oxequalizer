TEMPLATE = app

QT += qml quick widgets multimedia

SOURCES += sources/controller.cpp \
    sources/main.cpp \
    sources/oxbandfilter.cpp \
    sources/oxequalizer.cpp \
    sources/oxinput.cpp \
    sources/oxoutput.cpp \
    sources/oxvu.cpp

HEADERS += headers/controller.h \
    headers/oxbandfilter.h \
    headers/oxequalizer.h \
    headers/oxinput.h \
    headers/oxoutput.h \
    headers/oxvu.h

INCLUDEPATH += headers

unix {
LIBS += -lrfftw -lfftw
}

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/fftw-3.3.4-dll32 -llibfftw3f-3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/fftw-3.3.4-dll32 -llibfftw3f-3d

INCLUDEPATH += $$PWD/fftw-3.3.4-dll32
DEPENDPATH += $$PWD/fftw-3.3.4-dll32
