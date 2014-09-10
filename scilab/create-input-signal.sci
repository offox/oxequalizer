//
// Author: Oswaldo Fratini Filho
// Date: 08/09/2014
//
// Script to create input signal to test of OxEqualizer
//

// Number of samples
N = 65536

// Sample rate
sampleRate = 65536

// Samples
n = [0: N];

// Signal
s = cos(2 * %pi * 1000 * n / N) + cos(2 * %pi * 8000 * n / N) + cos(2 * %pi * 16000 * n / N) ;

// Fast Fourier Transform
y = fft(s);

//s is real so the fft response is conjugate symmetric and we retain only the first N/2 points
f = sampleRate *(0:(N / 2)) / N; 

// Frquencies
n = size(f, '*');
clf();

plot(f, abs(y(1:n)));

m = max(s);

s1 = s + m;

fator = 255 / (m * 2);

s2 = s1 * fator;

fprintfMat("tmp.dat", s1, "%f")

unix_g('sed -e ''s/\s\+/\n/g'' tmp.dat > tmp2.dat')
unix_g('sed -e ''s/\./,/g'' tmp2.dat > tmp3.dat')
unix_g('head -n -2 tmp3.dat > input-signal.dat')



