#ifndef OXVU_H
#define OXVU_H

#include <QObject>

#include <fftw.h>

class OxVu : public QObject
{
    Q_OBJECT
public:
    explicit OxVu(QObject *parent = 0);

    void newSpectrum();

private:
    static const int N = 48000;

    void fft(fftw_real *in, fftw_real *powerSpectrum, int n);

public slots:

};

#endif // OXVU_H
