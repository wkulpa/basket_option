#ifndef BSMODEL_H_INCLUDED
#define BSMODEL_H_INCLUDED

#include "Matrix.h"

using namespace std;

typedef Vector Price;

class BSModel{
public:
    BSModel(Price S0_, double r_, Matrix C_);

    void GeneratePrice(double T, Price& S);
    double getR() const {return r;};
private:
    Price S0, sigma;
    Matrix C;
    double r;
};

#endif // BSMODEL_H_INCLUDED
