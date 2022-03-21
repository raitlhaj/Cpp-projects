#include<iostream>
#include"BSPricing.h"
#include"../Proba/Law.cpp"
#include<math.h>

using namespace std;
//action
Action::Action(){ volatility=0.0, r=0.0, T=0, S0=0;};
Action::Action(double S0,double r,double sig,int maturity)
{this->S0=S0,volatility=sig,this->r=r,T=maturity;};

void Action::affiche(){ cout<<"[Stock]->S0= "<<S0<<", free rate "<<r<<", Volatility= " <<volatility<<endl;};

//Option
Option::Option(){stock=Action(),strike=0,this->e=1,this->t=0;}
Option::Option(Action st,double K,int e ,double t)
{
stock=st;
strike=K;
this->e=e;
this->t=t;
}
Action Option::getStock(){return stock;}
double Option::gett(){ return t;}
double Option::getK(){return strike;}
int Option::getE(){return e;}

void Option::affiche(){ 
cout<<"[Option]->[Premium 0 is:"<<price()<<",Premium 1:"<<BSformula()<<"], Strike is:"<<strike<<", Payoff is: "<< ((e*(stock.S0-strike)>0)?e*(stock.S0-strike):0)<<endl;
};
double Option::price()
{
        double theta=stock.T-t, sig=stock.volatility;
        double dl = (log(stock.S0/strike)+(stock.r+sig*sig*0.5)*theta)/ sig*sqrt(theta);
        double d2 = dl - sig;
        return e*stock.S0*phi1(e*dl) - e*strike*exp(-stock.r*theta)* phi1(e*d2);
}

double Option::BSformula()
{ 
double theta=stock.T-t, sig=stock.volatility,dS=0.01, sig2=2*sig*sig*theta, r2=stock.r*theta-sig2/4, aux=0;
for(double Sp=0.001; Sp<500; Sp+=dS)
aux += (e*(Sp-strike)>0?e*(Sp-strike):0)*exp(-pow(log(Sp/stock.S0)-r2,2)/sig2)*dS/Sp;
return aux * exp(-stock.r*theta)/sqrt(8*atan(1)*theta)/sig;
}