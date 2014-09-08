#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QUrl>

#include "oxinput.h"
#include "oxoutput.h"
#include "oxvu.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = 0);

    void init();

private:
    OxInput *oxInput;
    OxOutput *oxOutput;
    OxVu *oxVuIn;
    OxVu *oxVuOut;

signals:

public slots:
    Q_INVOKABLE void setAudioUrl(const QUrl &url);
    Q_INVOKABLE void play();
    Q_INVOKABLE void stop();
};

#endif // CONTROLLER_H
