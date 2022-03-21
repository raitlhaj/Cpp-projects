#include<iostream>
#include<fstream>
#include<random>
#include<vector>
#include"BSPricing.h"
#include"MonteCarlo.h"

    MonteCarlo::MonteCarlo(){eps=1.e-50, pi2 =8*atan(1);}
    MonteCarlo::MonteCarlo(int N,Option option){ this->N=N,this->option=option, T=option.getStock().T,eps=1.e-50, pi2 =8*atan(1);}

    std::vector<double> MonteCarlo::boxmuller(){
        std::vector<double> v;
        v.push_back(sqrt(-2*log(uniform()))*cos(8*atan(1)*uniform()));
        v.push_back(sqrt(-2*log(uniform()))*sin(8*atan(1)*uniform()));
        return v;}

    double MonteCarlo::S(int T ){return option.getStock().S0*exp( (option.getStock().r-pow(option.getStock().volatility,2)/2)*T+option.getStock().volatility*boxmuller()[1]);}
    double MonteCarlo::price()
    {
        double premium=0, theta=T-option.gett(),St,europeanVal,intrinsecVal;
        std::ofstream outfile1, outfile2;
        outfile1.open("StockPrice.dat",std::ios::out); 
        outfile2.open("Premium.dat",std::ios::out); 

        for (int i=0;i<N;i++)
        {
            double ST=S(T);
            europeanVal=exp(-option.getStock().r*theta)*((ST-option.getK())*option.getE()>0)?(ST-option.getK())*option.getE():0; 

            for (int k=0;k<T;k++) 
            {   
                //intrinsec value
                outfile1<<" "<<S(k);
                St=S(k);
                intrinsecVal=exp(-option.getStock().r*theta)*((St-option.getK())*option.getE()>0)?(St-option.getK())*option.getE():0; 
               // if(europeanVal<intrinsecVal ) { std::cout<<std::endl<< "Sec:"<<i<<" Exec possible at time="<<k<< "premium="<<intrinsecVal<<" vs. "<<europeanVal;}
            }
            outfile1<<std::endl;

            outfile2<<std::endl<<europeanVal;
            premium+=europeanVal;
        }

        outfile1.close();
        outfile2.close();
        return premium/N;
    }    

    void MonteCarlo::affiche()
    {
        std::cout<<std::endl<<"[MonteCarlo]->Premium "<<N<<"-simulation: "<<price();
    } 
