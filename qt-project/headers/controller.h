#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QUrl>

#include "oxinput.h"
#include "oxoutput.h"
#include "oxvu.h"
#include "oxequalizer.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = 0);

    void init();

    Q_INVOKABLE OxVu *oxVuIn() {
        return d_oxVuIn;
    }

    Q_INVOKABLE OxVu *oxVuOut() {
        return d_oxVuOut;
    }

    Q_INVOKABLE OxEqualizer *oxEqualizer() {
        return d_oxEqualizer;
    }

private:
    OxInput *d_oxInput;
    OxOutput *d_oxOutput;
    OxVu *d_oxVuIn;
    OxVu *d_oxVuOut;
    OxEqualizer *d_oxEqualizer;

    QVector<double> *d_x;
    QVector<double> *d_y;

signals:
    void oxVuChanged();
    void fileLoaded();

private slots:
    void process();

public slots:
    Q_INVOKABLE void setAudioUrl(const QUrl &url);
    Q_INVOKABLE void loadFile(const QUrl &url);
    Q_INVOKABLE void play();
    Q_INVOKABLE void stop();
};

#endif // CONTROLLER_H
