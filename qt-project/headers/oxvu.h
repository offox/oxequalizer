#ifndef OXVU_H
#define OXVU_H

#include <QByteArray>
#include <QMap>
#include <QObject>
#include <QString>
#include <QVariantMap>

//#if defined(Q_WS_X11)
#include <rfftw.h>
//#else
//#include <fftw3.h>
//#endif

class OxVu : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double value31 READ value31 NOTIFY spectrumChanged)
    Q_PROPERTY(double value62 READ value62 NOTIFY spectrumChanged)
    Q_PROPERTY(double value125 READ value125 NOTIFY spectrumChanged)
    Q_PROPERTY(double value250 READ value250  NOTIFY spectrumChanged)
    Q_PROPERTY(double value500 READ value500 NOTIFY spectrumChanged)
    Q_PROPERTY(double value1k READ value1k NOTIFY spectrumChanged)
    Q_PROPERTY(double value2k READ value2k NOTIFY spectrumChanged)
    Q_PROPERTY(double value4k READ value4k  NOTIFY spectrumChanged)
    Q_PROPERTY(double value8k READ value8k NOTIFY spectrumChanged)
    Q_PROPERTY(double value16k READ value16k NOTIFY spectrumChanged)


public:
    explicit OxVu(QObject *parent = 0);

    void init();

    void setBuffer(QVector<double> *buf);

    double value31() {
        return d_value31;
    }

    double value62() {
        return d_value62;
    }

    double value125() {
        return d_value125;
    }

    double value250() {
        return d_value250;
    }

    double value500() {
        return d_value500;
    }

    double value1k() {
        return d_value1k;
    }

    double value2k() {
        return d_value2k;
    }

    double value4k() {
        return d_value4k;
    }

    double value8k() {
        return d_value8k;
    }

    double value16k() {
        return d_value16k;
    }

private:
    double d_value31;
    double d_value62;
    double d_value125;
    double d_value250;
    double d_value500;
    double d_value1k;
    double d_value2k;
    double d_value4k;
    double d_value8k;
    double d_value16k;


    void fft(fftw_real *in, fftw_real *powerSpectrum, int n);

signals:
    void fftFinished();
    void spectrumChanged();
};

#endif // OXVU_H
