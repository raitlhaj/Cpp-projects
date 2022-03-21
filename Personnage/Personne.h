#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>

class Personne
{
 protected:
 std::string name;int age;char gender;

 public:
 Personne();
 Personne(Personne&);
 Personne(std::string,int,char);
 virtual std::string affiche();
};


class Homme:public Personne
{
  private:
  
  public:
  Homme(std::string , int , char );
  virtual std::string affiche();
};

class Femme:public Personne
{
  private:
  
  public:
  Femme(std::string , int , char );
  virtual std::string affiche();
}; 

#endif //PERSONNE_H