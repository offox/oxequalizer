#ifndef OXEQUALIZER_H
#define OXEQUALIZER_H

#include <QObject>
#include <QVector>

#include "oxbandfilter.h"

class OxEqualizer : public QObject
{
    Q_OBJECT

public:
    OxEqualizer();

    void init();

    void equalize(QVector<double> *x, QVector<double> *y);

    Q_INVOKABLE void setGain31(double gain);
    Q_INVOKABLE void setGain62(double gain);
    Q_INVOKABLE void setGain125(double gain);
    Q_INVOKABLE void setGain250(double gain);
    Q_INVOKABLE void setGain500(double gain);
    Q_INVOKABLE void setGain1k(double gain);
    Q_INVOKABLE void setGain2k(double gain);
    Q_INVOKABLE void setGain4k(double gain);
    Q_INVOKABLE void setGain8k(double gain);
    Q_INVOKABLE void setGain16k(double gain);

private:
    OxBandFilter d_oxBandFilter31;
    OxBandFilter d_oxBandFilter62;
    OxBandFilter d_oxBandFilter125;
    OxBandFilter d_oxBandFilter250;
    OxBandFilter d_oxBandFilter500;
    OxBandFilter d_oxBandFilter1k;
    OxBandFilter d_oxBandFilter2k;
    OxBandFilter d_oxBandFilter4k;
    OxBandFilter d_oxBandFilter8k;
    OxBandFilter d_oxBandFilter16k;

    QVector<double> *d_y31;
    QVector<double> *d_y62;
    QVector<double> *d_y125;
    QVector<double> *d_y250;
    QVector<double> *d_y500;
    QVector<double> *d_y1k;
    QVector<double> *d_y2k;
    QVector<double> *d_y4k;
    QVector<double> *d_y8k;
    QVector<double> *d_y16k;

    void clearAllOutput();
};

#endif // OXEQUALIZER_H
