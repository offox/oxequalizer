TEMPLATE = app

QT += qml quick widgets multimedia

LIBS += -lrfftw -lfftw

SOURCES += main.cpp \
    oxequalizer.cpp \
    oxinput.cpp \
    oxoutput.cpp \
    oxvu.cpp \
    controller.cpp

HEADERS += \
    oxequalizer.h \
    oxinput.h \
    oxoutput.h \
    oxvu.h \
    controller.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
