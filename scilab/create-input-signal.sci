//
// Author: Oswaldo Fratini Filho
// Date: 08/09/2014
//
// Script to create input signal to test of OxEqualizer
//

// Number of samples
N = 48000

// Sample rate
sampleRate = 48000 

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

fator = 255 / m;

s2 = round(s1 * fator);

// Save in the file
fid = mopen('input-signal.dat', 'w');

for i = N
    mfprintf(fid, "%d", s[i]);
end

mclose(fid);



