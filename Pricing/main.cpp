#include<iostream>
#include"BSPricing.cpp"
#include"MonteCarlo.cpp"
#include"VarianceReduction.cpp"
#include"BSPricing.h"
#include"MonteCarlo.h"
#include"Binomial.cpp"

const int T=2,t=0,M=100;
const int N=100;
const int L=100,call=1;                            // NB of sampling point for S
const double S0=100,K=100, volatility=0.2, r=0.1, b=0.6;

int main()
{
    ifstream infile("inputs.dat");
    Action stock(S0,r,volatility,T);               //Sig,r,S0,maturity
    Option option(stock,K,call,t);                 //Stock, Strike, C=1/P=-1,t
    MonteCarlo m(N,option);                        //Number of simulation and the option

    stock.affiche();                               //See console
    option.affiche();                              //See console
    m.affiche();                                   //See console
    ControlVariates(option,b,N,M);                 //See comp.dat file
    AntitheticVariates(option,N,M);                //See comp2.dat file

    //binomial tree
    Binomial b(S0,T*5,r,(1+r)*volatility,(-1+r)*volatility);
    b.constructTree();
    cout<<"\nEUROPEAN CALL: ";
    b.myOption("EU",'C',K);
    b.affiche();
    cout<<"\nAMERICAN CALL: ";
    b.myOption("AM",'C',K);
    b.affiche();
    cout<<"\nEUROPEAN PUT: ";
    b.myOption("EU",'P',K);
    b.affiche();
    cout<<"\nAMERICAN PUT: ";
    b.myOption("AM",'P',K);
    b.affiche();

    return 0;
}