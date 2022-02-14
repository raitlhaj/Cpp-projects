#include<iostream>
#include"Arme.h"



class Personnage{
private:
char nom;
int id;
int points;
Arme *armePointeur;
Arme armeValeur;

public:
int compteur;
Personnage(int , char);
void attaquer();
void aGagner();
bool estVivant();
void affiche();
void seBag(Personnage &);
void bataille(Personnage &);

};

