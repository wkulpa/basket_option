#include "BasketOption.h"
#include <cmath>
#include <iostream>

double BasketEuropeanOption::Payoff(const Price& S)
{
    double basketPrice=Weights^S;
  //  cout <<basketPrice << endl;
    switch(CallPut){
    case Call:
        if(basketPrice<K)
            return 0.0;
        else
            return basketPrice-K;
    case Put:
        if(basketPrice>K)
            return 0.0;
        else
            return K-basketPrice;
    }
    return 0.0;
}
double BasketOption::PriceByMC(BSModel& Model, long N)
{
   double H=0.0;
   Price S;
   for(long i=0; i<N; i++)
   {
      Model.GeneratePrice(T,S);
      H = (i*H + Payoff(S))/(i+1.0);
   }
   return exp(-Model.getR()*T)*H;
}
