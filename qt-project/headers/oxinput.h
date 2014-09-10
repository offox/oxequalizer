#ifndef OXINPUT_H
#define OXINPUT_H

//#include <QAudioFormat>
//#include <QAudioDecoder>
#include <QVector>
#include <QObject>
#include <QTimer>

class OxInput : public QObject
{
    Q_OBJECT
public:
    explicit OxInput(QObject *parent = 0);

    void init();

    bool setAudioFile(const QString &path);
    bool loadFile(const QString &path);
    void play();
    void stop();
    void setBuffer(QVector<double> *buf);

private:
    QTimer d_timer;
    QVector<double> *d_buf;

signals:
    void readyBuffer();
};

#endif // OXINPUT
