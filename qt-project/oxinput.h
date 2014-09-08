#ifndef OXINPUT_H
#define OXINPUT_H

#include <QAudioFormat>
#include <QAudioDecoder>

class OxInput : public QAudioDecoder
{
    Q_OBJECT
public:
    explicit OxInput(QObject *parent = 0);

    void init();

    bool setAudioFile(const QString &path);

private:
    int count;

    QAudioFormat audioFormat;

private slots:
    void readBuffer();
};

#endif // OXINPUT
