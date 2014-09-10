#include <QDebug>

#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
}

void
Controller::init() {
    d_oxInput = new OxInput();
    d_oxOutput = new OxOutput();
    d_oxVuIn = new OxVu();
    d_oxVuOut = new OxVu();
    d_oxEqualizer = new OxEqualizer;
    d_y = new QVector<double>();
    d_x = new QVector<double>();

    d_oxInput->init();
    d_oxVuIn->init();
    d_oxVuOut->init();
    d_oxEqualizer->init();

    d_oxInput->setBuffer(d_x);

    connect(d_oxInput, SIGNAL(readyBuffer()), SLOT(process()));
}

void
Controller::setAudioUrl(const QUrl &url) {
    d_oxInput->setAudioFile(url.path());
}

void
Controller::loadFile(const QUrl &url) {
    d_oxInput->loadFile(url.path());
    emit fileLoaded();
}


void
Controller::play() {
    d_oxInput->play();
}

void
Controller::stop() {
    d_oxInput->stop();
}

void
Controller::process() {
    d_y->clear();
    d_oxEqualizer->equalize(d_x, d_y);
    d_oxVuIn->setBuffer(d_x);
    d_oxVuOut->setBuffer(d_y);
}
