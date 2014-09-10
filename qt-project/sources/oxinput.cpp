//#include <QAudioBuffer>
#include <QDebug>
#include <QFile>

#include "oxinput.h"

OxInput::OxInput(QObject *parent) :
    QObject(parent)
{
}

void
OxInput::init() {
    d_timer.setInterval(500);
    connect(&d_timer, SIGNAL(timeout()), SIGNAL(readyBuffer()));
    /*
    audioFormat.setChannelCount(1);
    audioFormat.setCodec("audio/x-raw");
    audioFormat.setSampleType(QAudioFormat::UnSignedInt);
    audioFormat.setSampleRate(48000);
    audioFormat.setSampleSize(8);

    this->setAudioFormat(audioFormat);

    connect(this, SIGNAL(bufferReady()), this, SLOT(readBuffer()));
    */
}

bool
OxInput::setAudioFile(const QString &path) {
    Q_UNUSED(path)
    //this->setSourceFilename(path);
    return true;
}

bool
OxInput::loadFile(const QString &path) {
    FILE* file = fopen(path.toLatin1().data(), "r");

    if (file == NULL)
    {
        printf("Error opening file!");
        return false;
    }

    char line[16];

    while (fgets(line, 16, file))
    {
        char *tmp = strdup(line);
        d_buf->append(atof(tmp));
        //qDebug() << atof(tmp);
        free(tmp);
    }

    //qDebug() << d_buf->size();

    fclose(file);

    return true;
}

void
OxInput::play() {
    d_timer.start();
}

void
OxInput::stop() {
    d_timer.stop();
}

void
OxInput::setBuffer(QVector<double> *buf) {
    d_buf = buf;
}
