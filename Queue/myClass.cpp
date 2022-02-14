#include <iostream>
#include <string>
#include "myClass.h"

using namespace std;

MyClass::MyClass(int a,int b):regVar(a),constVar(b){};

string MyClass::affiche()
{
    return "regVar="+getReg()+" ,constVar="+getCons();
}

MyClass::~MyClass()
{
 cout<<"\n \nDestructeur";
}

int MyClass::getReg(){ return regVar;}
int MyClass::getCons(){ return constVar;}

int main()
{
 MyClass  m(10,12);
 cout<<m.getReg();

return 0;
}