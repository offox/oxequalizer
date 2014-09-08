//#include <QAudioBuffer>

#include "oxinput.h"

OxInput::OxInput(QObject *parent) :
    QAudioDecoder(parent)
{
}

void
OxInput::init() {
    audioFormat.setChannelCount(1);
    audioFormat.setCodec("audio/x-raw");
    audioFormat.setSampleType(QAudioFormat::UnSignedInt);
    audioFormat.setSampleRate(48000);
    audioFormat.setSampleSize(8);

    this->setAudioFormat(audioFormat);

    connect(this, SIGNAL(bufferReady()), this, SLOT(readBuffer()));
}

bool
OxInput::setAudioFile(const QString &path) {
    this->setSourceFilename(path);
}

void
OxInput::readBuffer() {
    QAudioBuffer audioBuffer = read();
    qDebug() << "Audio Duration: " << this->duration();
    qDebug() << "Audio Buffer size: " << audioBuffer.sampleCount();
}



