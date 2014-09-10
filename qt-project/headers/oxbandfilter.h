#ifndef OXBANDFILTER_H
#define OXBANDFILTER_H

#include <QVector>

class OxBandFilter
{
public:
    OxBandFilter();

    void init();

    void setParameters(double alpha, double beta, double gama);
    void setGain(double gain);
    void applyFilter(QVector<double> *x, QVector<double> *y);

private:
    double d_alpha;
    double d_beta;
    double d_gama;
    double d_gain;
    double d_xZ2;
    double d_yZ1;
    double d_yZ2;
};

#endif // OXBANDFILTER_H
