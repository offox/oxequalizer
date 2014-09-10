#include <QDebug>

#include "oxbandfilter.h"

OxBandFilter::OxBandFilter()
{
}

void
OxBandFilter::init()
{
   d_gain = 1.0;

   d_alpha = 0.0;
   d_beta = 0.0;
   d_gama = 0.0;

   d_xZ2 = 0.0;
   d_yZ1 = 0.0;
   d_yZ2 = 0.0;
}

void
OxBandFilter::setParameters(double alpha, double beta, double gama)
{
    d_alpha = alpha;
    d_beta = beta;
    d_gama = gama;
}

void
OxBandFilter::setGain(double gain)
{
    d_gain = gain;
}

void
OxBandFilter::applyFilter(QVector<double> *x, QVector<double> *y)
{
    int i;
    int xSize = x->size();

    double acc;
    double sum;

    for(i = 0; i < xSize; i++) {
        acc = 0.0;
        if (i == 0) {
            acc = d_alpha * x->at(i);
            acc += - d_alpha * d_xZ2;
            acc += d_gama * d_yZ1;
            acc += - d_beta * d_yZ2;
            sum = d_gain * 2 * acc;
        } else if (i == 1) {
            acc = d_alpha * x->at(i);
            acc += - d_alpha * d_xZ2;
            acc += d_gama * y->at(i - 1);
            acc += - d_beta * d_yZ2;
            sum = d_gain * 2 * acc;
        } else {
            acc = d_alpha * x->at(i);
            acc += - d_alpha * x->at(i - 2);
            acc += d_gama * y->at(i - 1);
            acc += - d_beta * y->at(i - 2);
            sum = d_gain * 2 * acc;
        }

        if (qIsNaN(sum)) {
            y->append(0.0);
        } else {
            y->append(sum);
        }

        //qDebug() << "y: " << y->last();
    }

    d_xZ2 = x->at(i - 1);
    d_yZ1 = y->at(i);
    d_yZ2 = y->at(i - 1);
}
