#include<iostream>
#include"Personnage.h"
#include<cstdlib>

//#include<QApplication>

using namespace std;

Arme::Arme()
{
nombre=10;
type='A';
//nom="Clash";
};
Personnage::Personnage(int iD,char name)
{

armePointeur=new Arme();
armeValeur;
id=iD;
nom=name;
points=100;
compteur++;

}

bool Personnage::estVivant()
{
if(points>0)
return 1;
return 0;
}


void Personnage::affiche(){cout<<"Compteur est"<<compteur<<", My name is "<<nom<<", My ID="<<id<<" J'ai :"<<points<<" points, mon arme dynamique c'est"<<armePointeur<<"arme statique"<<armeValeur<<endl;}
void Personnage::attaquer(){points-=25;}
void Personnage::aGagner(){points=points+10;}

void Personnage::seBag(Personnage& p)
{
if(rand()%3>5)
points-=rand()%7;
else
p.points-=rand()%7;
}


void Personnage::bataille(Personnage& p){

for(int i=0;i<100 & Personnage::estVivant()!=false & p.Personnage::estVivant()!=false;i++)
{ Personnage::seBag( p);}

if(!Personnage::estVivant())
cout <<" Mort de personnage 1"<<endl;
if(!p.Personnage::estVivant())
cout <<" Mort de personnage 2"<<endl;

}
 
int main()
{

Personnage p1( 1213,'A');
Personnage p2(8546,'D');



p1.affiche();
p2.affiche();
p1.seBag(p2);
p1.affiche();
p2.affiche();
p2.bataille(p1);
p1.affiche();
p2.affiche();

//cout<<rand()%10 -1<<"Vie="<<p1.estVivant()<<endl;

return 0;
}
