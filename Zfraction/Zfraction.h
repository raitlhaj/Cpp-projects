#include<iostream>

class Zfraction{

private:
int num, den;

public:
int getNum();
int getDen();
//consructeurs:
Zfraction(int,int);
Zfraction(int);
Zfraction();

//affichage
void affiche();

//surcharge des operateurs interne
Zfraction operator *=(Zfraction &);
Zfraction operator /=(Zfraction &);
Zfraction operator +=(Zfraction &);
Zfraction operator -=(Zfraction &);
};

//surcharge des operateurs externe
Zfraction operator *(Zfraction&,Zfraction&);
Zfraction operator /(Zfraction&,Zfraction&);
Zfraction operator +(Zfraction&,Zfraction&);
Zfraction operator -(Zfraction&,Zfraction&);
