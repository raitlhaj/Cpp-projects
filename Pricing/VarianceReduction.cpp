#include<iostream>
#include<fstream>
#include<math.h>
//#include"BSPricing.cpp"
//#include"MonteCarlo.cpp"
#include"BSPricing.h"
#include"MonteCarlo.h"
#include"../Proba/Law.h"

void ControlVariates(Option option,double b, int N,int M){

    const double dt=1./M;
    double U1,U2,Z1,Z2,S1,S2,premium=0 ,theta=option.getStock().T-option.gett();
    std::ofstream ff("comp.dat");
    
     for(double x=0;x<option.getStock().T;x+=dt)
      {
        MonteCarlo m(N,option);
        for(int i=0;i<N;i++)
        {
         U1=uniform();
         U2=uniform();
         Z1=sqrt(-2*log(U1))*cos(8*atan(1)*U2);
         Z2=sqrt(-2*log(U1))*sin(8*atan(1)*(U2));
         //std::cout<<"\nS0="<<option.getStock().S0<<"\t r="<< option.getStock().r<<"\tsigu="<<pow(option.getStock().volatility,2)/2<<"\t T="<<option.getStock().T<<"\t Alea="<<option.getStock().volatility*Z1;
         S1= option.getStock().S0*exp( (option.getStock().r-pow(option.getStock().volatility,2)/2)*option.getStock().T+option.getStock().volatility*Z1*sqrt(option.getStock().T));
         premium+= exp(-option.getStock().r*theta)*(((S1-option.getK())*option.getE()>0)? (S1-option.getK())*option.getE():0);
         premium-=b*(S1- exp(option.getStock().r*option.getStock().T)*option.getStock().S0 );
         ff<<"[Antithetic Variates]-> 1st premium="<<premium<<"]"<<std::endl;
        }
      }
         ff<<std::endl<<"MonteCarlo premium by using control variates to reduce the variance is "<<premium/(2*N*M)<<std::endl;
         std::cout<<std::endl<<"[MonteCarlo Control]-> premium: "<<premium/(2*N*M);
};

void AntitheticVariates(Option option, int N,int M){

    const double dt=1./M;
    double U1,U2,Z1,Z2,S1,S2,prem1=0,prem2=0,premium=0 ,theta=option.getStock().T-option.gett();
    std::ofstream ff("comp2.dat");
    
     for(double x=0;x<option.getStock().T;x+=dt)
      {
        MonteCarlo m(N,option);
        for(int i=0;i<N;i++)
        {
         U1=uniform();
         U2=uniform();
         Z1=sqrt(-2*log(U1))*cos(8*atan(1)*U2);
         Z2=sqrt(-2*log(U1))*sin(8*atan(1)*(U2));
         //std::cout<<"\nS0="<<option.getStock().S0<<"\t r="<< option.getStock().r<<"\tsigu="<<pow(option.getStock().volatility,2)/2<<"\t T="<<option.getStock().T<<"\t Alea="<<option.getStock().volatility*Z1;
         S1= option.getStock().S0*exp( (option.getStock().r-pow(option.getStock().volatility,2)/2)*option.getStock().T+option.getStock().volatility*Z1*sqrt(option.getStock().T));
         S2= option.getStock().S0*exp( (option.getStock().r-pow(option.getStock().volatility,2)/2)*option.getStock().T-option.getStock().volatility*Z1*sqrt(option.getStock().T));

         prem1= exp(-option.getStock().r*theta)*(((S1-option.getK())*option.getE()>0)? (S1-option.getK())*option.getE():0);
         prem2=  exp(-option.getStock().r*theta)*(((S2-option.getK())*option.getE()>0)? (S2-option.getK())*option.getE():0);
         premium+=prem1+prem2;
         ff<<"[Antithetic Variates][U1-U2-Z1-Z2-S1-S2]:["<<U1<<" "<<U2<<" "<<Z1<<" "<<Z2<<" "<<S1<<" "<<S2<<" 1st prem="<<prem1<<" ;2nd prem="<<prem2<<"]"<<std::endl;
        }
      }
         ff<<std::endl<<"MonteCarlo premium by using antithetic variates to reduce the variance is "<<premium/(4*N*M)<<std::endl;
         std::cout<<std::endl<<"[MonteCarlo Antithetic]-> premium: "<<premium/(4*N*M)<<std::endl;   
};
