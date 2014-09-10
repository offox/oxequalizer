#include <QDebug>

#include "oxequalizer.h"

OxEqualizer::OxEqualizer()
{
}

void
OxEqualizer::init() {
    d_oxBandFilter31.init();
    d_oxBandFilter62.init();
    d_oxBandFilter125.init();
    d_oxBandFilter250.init();
    d_oxBandFilter500.init();
    d_oxBandFilter1k.init();
    d_oxBandFilter2k.init();
    d_oxBandFilter4k.init();
    d_oxBandFilter8k.init();
    d_oxBandFilter16k.init();

    d_y31 = new QVector<double>;
    d_y62 = new QVector<double>;
    d_y125 = new QVector<double>;
    d_y250 = new QVector<double>;
    d_y500 = new QVector<double>;
    d_y1k = new QVector<double>;
    d_y2k = new QVector<double>;
    d_y4k = new QVector<double>;
    d_y8k = new QVector<double>;
    d_y16k = new QVector<double>;

    d_oxBandFilter31.setParameters(0.000723575, 0.49855285, 0.49855285);
    d_oxBandFilter62.setParameters(0.001445062, 0.497109876, 0.997077038);
    d_oxBandFilter125.setParameters(0.002904926, 0.494190149, 0.994057064);
    d_oxBandFilter250.setParameters(0.005776487, 0.488447026, 0.987917799);
    d_oxBandFilter500.setParameters(0.011422552, 0.477154897, 0.975062733);
    d_oxBandFilter1k.setParameters(0.02234653, 0.455306941, 0.947134157);
    d_oxBandFilter2k.setParameters(0.04286684, 0.414266319, 0.88311345);
    d_oxBandFilter4k.setParameters(0.079552886, 0.340894228, 0.728235763);
    d_oxBandFilter8k.setParameters(0.1199464, 0.2601072, 0.3176087);
    d_oxBandFilter16k.setParameters(0.159603, 0.1800994, -0.4435172);
}

void
OxEqualizer::equalize(QVector<double> *x, QVector<double> *y) {
    int xSize = x->size();

    this->clearAllOutput();

    d_oxBandFilter31.applyFilter(x, d_y31);
    d_oxBandFilter62.applyFilter(x, d_y62);
    d_oxBandFilter125.applyFilter(x, d_y125);
    d_oxBandFilter250.applyFilter(x, d_y250);
    d_oxBandFilter500.applyFilter(x, d_y500);
    d_oxBandFilter1k.applyFilter(x, d_y1k);
    d_oxBandFilter2k.applyFilter(x, d_y2k);
    d_oxBandFilter4k.applyFilter(x, d_y4k);
    d_oxBandFilter8k.applyFilter(x, d_y8k);
    d_oxBandFilter16k.applyFilter(x, d_y16k);

    double sum;
    for (int i = 0; i < xSize; i++) {
        sum = 0.0;
        sum += d_y31->at(i);
        sum += d_y62->at(i);
        sum += d_y125->at(i);
        sum += d_y250->at(i);
        sum += d_y500->at(i);
        sum += d_y1k->at(i);
        sum += d_y2k->at(i);
        sum += d_y4k->at(i);
        sum += d_y8k->at(i);
        sum += d_y16k->at(i);
        y->append(sum);
    }
}

void
OxEqualizer::setGain31(double gain) {
    d_oxBandFilter31.setGain(gain);
}

void
OxEqualizer::setGain62(double gain) {
    d_oxBandFilter62.setGain(gain);
}

void
OxEqualizer::setGain125(double gain) {
    d_oxBandFilter125.setGain(gain);
}

void
OxEqualizer::setGain250(double gain) {
    d_oxBandFilter250.setGain(gain);
}

void
OxEqualizer::setGain500(double gain) {
    d_oxBandFilter500.setGain(gain);
}

void
OxEqualizer::setGain1k(double gain) {
    d_oxBandFilter1k.setGain(gain);
}

void
OxEqualizer::setGain2k(double gain) {
    d_oxBandFilter2k.setGain(gain);
}

void
OxEqualizer::setGain4k(double gain) {
    d_oxBandFilter4k.setGain(gain);
}

void
OxEqualizer::setGain8k(double gain) {
    d_oxBandFilter8k.setGain(gain);
}

void
OxEqualizer::setGain16k(double gain) {
    d_oxBandFilter16k.setGain(gain);
}

void
OxEqualizer::clearAllOutput() {
    d_y31->clear();
    d_y62->clear();
    d_y125->clear();
    d_y250->clear();
    d_y500->clear();
    d_y1k->clear();
    d_y2k->clear();
    d_y4k->clear();
    d_y8k->clear();
    d_y16k->clear();
}




