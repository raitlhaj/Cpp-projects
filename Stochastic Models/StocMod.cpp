#include<iostream>
#include"StocMod.h"

using namespace std;
//action
Action::Action(){
volatility=0.5;
rate=0.07;
T=1;
price0=100;
};
Action::Action(double sig,double r,double S0,int expiration)
{
volatility=sig;
rate=r;
T=expiration;
price0=S0;
};
void Action::affiche(){ cout<<"Prix initial de votre action est : "<<price0<<", avec une volatilité de : " <<volatility<<endl;
};

//Option

Option::Option(Action st,double K)
{
action=st;
strike=K;
};
void Option::affiche(){ 
cout<<"Le prix d'exercice de l'option est : "<<strike<<"Payoff: "<< (action.getPrice0()-strike)<<endl;
};

int main()
{
Action st(0.5,0.07,100,5);
Option call(st,100);

st.affiche();
call.affiche();

return 0;
}
