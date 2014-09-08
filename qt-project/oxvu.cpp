#include <rfftw.h>

#include "oxvu.h"

OxVu::OxVu(QObject *parent) :
    QObject(parent)
{
}

void
OxVu::newSpectrum() {
    fftw_real input[N];
    fftw_real powerSpectrum[N / 2 + 1];

    fft(input, powerSpectrum, N);
}

void
OxVu::fft(fftw_real *in, fftw_real *powerSpectrum, int n) {
     fftw_real out[n];
     rfftw_plan plan;
     int k;

     plan = rfftw_create_plan(n, FFTW_REAL_TO_COMPLEX, FFTW_ESTIMATE);
     //rfftw_one(plan, in, out);
     rfftw_one(plan, in, powerSpectrum);
     return;
     powerSpectrum[0] = out[0]*out[0];  /* DC component */

     for (k = 1; k < (n+1)/2; ++k)  /* (k < N/2 rounded up) */
     {
          powerSpectrum[k] = out[k]*out[k] + out[n-k]*out[n-k];
     }
     if (n % 2 == 0) /* N is even */
     {
          powerSpectrum[n/2] = out[n/2]*out[n/2];  /* Nyquist freq. */
     }

     rfftw_destroy_plan(plan);
}
