#include <QDebug>

#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
}

void
Controller::init() {
    oxInput = new OxInput();
    oxOutput = new OxOutput();
    oxVuIn = new OxVu();
    oxVuOut = new OxVu();

    oxInput->init();
}

void
Controller::setAudioUrl(const QUrl &url) {
    oxInput->setAudioFile(url.path());
}

void
Controller::play() {
    oxInput->start();
}

void
Controller::stop() {
    oxInput->stop();
}
