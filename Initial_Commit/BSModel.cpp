#include "BSModel.h"
#include <cmath>
#include <time.h>
#include <stdlib.h>
const double pi=4.0*atan(1.0);

double Gauss()
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}
Vector Gauss(int d)
{
    Vector Z(d);
    for (int j=0; j<d; j++)
        Z[j] = Gauss();
    return Z;
}
BSModel::BSModel(Price S0_, double r_, Matrix C_):
    S0(S0_),C(C_),r(r_)
{
    srand(time(NULL));
    sigma.resize(S0.size());

    for(size_t i = 0; i<S0.size(); ++i)
        sigma[i]=sqrt(C[i]^C[i]);
}
void BSModel::GeneratePrice(double T, Price& S)
{
    S= S0*exp((T)*(r+(-0.5)*sigma*sigma)+sqrt(T)*(C*Gauss(S0.size())));
}
