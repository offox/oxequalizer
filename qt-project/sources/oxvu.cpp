#include <QDebug>
#include <QEventLoop>

#include "oxvu.h"

OxVu::OxVu(QObject *parent) :
    QObject(parent)
{
}

void
OxVu::init() {
    d_value31 = 1;
    d_value62 = 1;
    d_value125  = 1;
    d_value250 = 1;
    d_value500 = 1;
    d_value1k = 1;
    d_value2k = 1;
    d_value4k = 1;
    d_value8k = 1;
    d_value16k = 1;

    emit spectrumChanged();
}

void
OxVu::setBuffer(QVector<double> *buf) {
    int N = buf->size();

    fftw_real input[N];
    fftw_real powerSpectrum[N / 2 + 1];

    for (int i = 0; i < N; i++) {
        input[i] = buf->at(i);
    }

    fft(input, powerSpectrum, N);

    d_value31 = powerSpectrum[31];
    d_value62 = powerSpectrum[62];
    d_value125 = powerSpectrum[125];
    d_value250 = powerSpectrum[250];
    d_value500 = powerSpectrum[500];
    d_value1k = powerSpectrum[1000];
    d_value2k = powerSpectrum[2000];
    d_value4k = powerSpectrum[4000];
    d_value8k = powerSpectrum[8000];
    d_value16k = powerSpectrum[16000];

    qDebug() << (double)powerSpectrum[31];
    qDebug() << (double)powerSpectrum[62];
    qDebug() << (double)powerSpectrum[125];
    qDebug() << (double)powerSpectrum[250];
    qDebug() << (double)powerSpectrum[500];
    qDebug() << (double)powerSpectrum[1000];
    qDebug() << (double)powerSpectrum[2000];
    qDebug() << (double)powerSpectrum[4000];
    qDebug() << (double)powerSpectrum[8000];
    qDebug() << (double)powerSpectrum[16000];

    emit spectrumChanged();
}

void
OxVu::fft(fftw_real *in, fftw_real *powerSpectrum, int n) {
     fftw_real out[n];
     rfftw_plan plan;
     int k;

     plan = rfftw_create_plan(n, FFTW_REAL_TO_COMPLEX, FFTW_ESTIMATE);
     rfftw_one(plan, in, out);
     //rfftw_one(plan, in, powerSpectrum);
#if 1
     powerSpectrum[0] = out[0] * out[0];  /* DC component */
     if (qIsNaN(powerSpectrum[k])) {
         powerSpectrum[k] = 0.0;
     }

     for (k = 1; k < (n + 1) / 2; ++k)  /* (k < N/2 rounded up) */
     {
          powerSpectrum[k] = out[k] * out[k] + out[n - k] * out[n - k];
          if (qIsNaN(powerSpectrum[k])) {
              powerSpectrum[k] = 0.0;
          }
     }
     if (n % 2 == 0) /* N is even */
     {
         powerSpectrum[n / 2] = out[n / 2] * out[n / 2];  /* Nyquist freq. */
         if (qIsNaN(powerSpectrum[k])) {
             powerSpectrum[k] = 0.0;
         }
     }
#endif

     rfftw_destroy_plan(plan);
}
