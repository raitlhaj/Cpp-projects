#include<iostream>
#include<string>
#include"Zfraction.h"

using namespace std;

int Zfraction::getNum(){return num;};
int Zfraction::getDen(){return den;};

Zfraction::Zfraction(int p, int q)
{
num=p;
den=q;
};
Zfraction::Zfraction(int q)
{
num=1;
den=q;
};
Zfraction::Zfraction()
{
num=0;
den=1;
};


//surcharge des operateurs internes
Zfraction Zfraction::operator *=(Zfraction & z)
{
num=z.num*num;
den=z.den*den;
}

Zfraction Zfraction::operator /=(Zfraction & z)
{
den=z.num*den;
num=z.den*num;
}

Zfraction Zfraction::operator +=(Zfraction & z)
{
num=z.num*den+z.den*num;
den=z.den*den;
}

Zfraction Zfraction::operator -=(Zfraction & z)
{
num=z.num*den-z.den*num;
den=z.den*den;
}

//surcharge des operateurs externes
Zfraction operator *(Zfraction& z,Zfraction& x)
{
Zfraction copy(z.getNum()*x.getNum(),z.getDen()*x.getDen());
cout <<endl<<"Comment ?:"<<endl<<"("<<z.getNum()<<"*"<<x.getNum()<<")"<<endl<<"------"<<endl<<"("<<z.getDen()<<"*"<<x.getDen()<<")";
return copy;

}

Zfraction operator /(Zfraction& z,Zfraction& x)
{
Zfraction copy(z.getDen()*x.getNum(),z.getNum()*x.getDen());
cout <<endl<<"Comment ?:"<<endl<<"("<<z.getDen()<<"*"<<x.getNum()<<")"<<endl<<"------"<<endl<<"("<<z.getNum()<<"*"<<x.getDen()<<")";
return copy;
}

Zfraction operator +(Zfraction& z,Zfraction& x)
{
Zfraction copy(z.getNum()*x.getDen()+z.getDen()*x.getNum(),z.getDen()*x.getDen());
cout <<endl<<"Comment ?:"<<endl<<"("<<z.getDen()<<"*"<<x.getNum()<<"+"<<x.getDen()<<"*"<<z.getNum()<<")"<<endl<<"-------"<<endl<<"("<<z.getDen()<<"*"<<x.getDen()<<")";
return copy;
}

Zfraction operator -(Zfraction& z,Zfraction& x)
{
Zfraction copy(z.getNum()*x.getDen()-z.getDen()*x.getNum(),z.getDen()*x.getDen());
cout <<endl<<"Comment ?:"<<endl<<"("<<z.getDen()<<"*"<<x.getNum()<<"-"<<x.getDen()<<"*"<<z.getNum()<<")"<<endl<<"--------"<<endl<<"("<<z.getDen()<<"*"<<x.getDen()<<")";
return copy;
return copy;


}

void Zfraction::affiche()
{
cout<<endl<<endl<<"Resultat : "<<endl<<num<<endl<<"---"<<endl<<den<<endl<<endl;
};


Zfraction returnFrac(string var)
{
string p={0,0,0,0,0},q={0,0,0,0,0};

for (int i=0;i<var.find("/");i++)
p[i]= var[i];
for (int i=var.find("/")+1;i<var[i]!='\0';i++)
q[i-var.find("/")-1]= var[i];

int nb= atoi(p.c_str());
int np=atoi(q.c_str());

Zfraction z(nb,np);
return z;
};


Zfraction indexDeOp(string var)
{
//
int index;
char op;

if(var.find("+")>0 & var.find("+")<1000)
{
index=var.find("+"); op='+';
}
if(var.find("-")>0 & var.find("-")<1000)
{
index=var.find("-"); op='-';
}
if(var.find("*")>0 & var.find("*")<1000)
{
index=var.find("*"); op='*';
}

string s1,s2;
s1=var.substr(0,index);
s2=var.substr(index+1,var.size());
//
Zfraction z1=returnFrac(s1);
Zfraction z2=returnFrac(s2);


switch(op)
{
case '+': return z1+z2; break;
case '-': return z1-z2; break;
case '*': return z1*z2; break;

default: cout<<"OPERATEUR INCONNU !"<<endl; return z1; break;
}
};

int main()
{

Zfraction f1(3,5),f2(7,8),f3(5),f4;
string var;
//f1.affiche();
//f2.affiche();
//f3.affiche();
//f4.affiche();
//f1/f2;
//f4=f1+f2;
//f4.affiche();

cout<<"[Operation sous forme a/b (+/-/*/'/')] :";
cin>>var;
//cout<<""<<var<<endl<<endl;
//cout<<count(var.begin(),var.end(),'/');
indexDeOp(var).affiche();






return 0;
};
