#ifndef BASKETOPTION_H_INCLUDED
#define BASKETOPTION_H_INCLUDED

#include "BSModel.h"

enum CallPut{
    Call,
    Put
};

class BasketOption{
public:
    double PriceByMC(BSModel& Model, long N);
    virtual double Payoff(const Price& S)=0;
protected:
    double T;
};

class BasketEuropeanOption: public BasketOption{
public:
    BasketEuropeanOption(double T_,double K_,enum CallPut CallPut_, const vector<double>& Weights_):
        CallPut(CallPut_), K(K_), Weights(Weights_)
        {T=T_;};
    virtual double Payoff(const Price& S);
private:
    enum CallPut CallPut;
    double K;
    Vector Weights;
};

#endif // BASKETOPTION_H_INCLUDED
