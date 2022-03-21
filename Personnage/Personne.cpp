#include"Personne.h"
#include<iostream>


Personne::Personne(){}
Personne::Personne(Personne &p){}
Personne::Personne(std::string name, int age, char gender='U')
{
   this->name=name;this->age=age;this->gender=gender;
}

std::string Personne::affiche()
{
 return "My name is: "+name+ " I'm: "+std::to_string(age)+ " my gender is: "+gender+"\n";
}

Homme::Homme(std::string name, int age, char gender):Personne(name, age,  gender){}
std::string Homme::affiche()
{
 return "HOMME : My name is: "+name+ " I'm: "+std::to_string(age)+ " my gender is: "+gender+"\n";
}


Femme::Femme(std::string name, int age, char gender):Personne(name, age,  gender){}
std::string Femme::affiche()
{
 return "Femme : My name is: "+name+ " I'm: "+std::to_string(age)+ " my gender is: "+gender+"\n";
}



