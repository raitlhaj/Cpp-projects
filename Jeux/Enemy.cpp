#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;
class Enemy 
{
    private:
    int gun;
    string name;

    protected:
    public:
    Enemy()
    {

    }
    Enemy(int a, string name)
    {
       gun=a;
       this->name=name;
    }

    void showMe()
    {
        cout<<"My name is "<<this->name<<"I've :"<<gun<<" guns !";
    }

    virtual void attack()
    {
        cout<<" Enemy attack >> ";
    }
    
    int getGun(){ return gun;}
    void modGun(int a){ gun=gun+a;}
};

class Monster : public Enemy
{
  public:
    Monster()
    {

    }
    void attack()
    {
        cout<<" Monter attack >>^^>> !!";
    }
};

class Ninja : public Enemy
{
  public:
    Ninja()
    {

    }
    void attack()
    {
        cout<<" Ninja attack XUUX !!";
    }

};

class Combat
{
    private:
    Enemy n1;
    Enemy n2;

    public:
    Combat ( Enemy n1, Enemy n2)
    {
        this->n1=n1;
        this->n2=n2;
    }
    void nouvellePartie()
    {
        srand(time(0));
        while(n1.getGun() && n2.getGun())
        {
             
             if( rand()%6>1)
             {
             cout<<"N1 bat N2! >>> N1="<<n1.getGun()<<" N2="<<n2.getGun() <<endl;
             n1.modGun(1);     
             n2.modGun(-1);      
             }
             else{
             cout<<"N2 bat N1! >>>  N1="<<n1.getGun()<<" N2="<<n2.getGun() <<endl;
             n1.modGun(-1);     
             n2.modGun(1);
             }

        }

        if(n1.getGun())
        cout<<"^-^ N1 won ^-^"<<endl;
        else cout<<"^-^ N2 won ^-^"<<endl;
        
    }
};

int main()
{
  Enemy n5(10,"hj"),n1(10,"lkl");
  Monster n2;
  Ninja n3;
  Enemy *n4=&n2;
  Combat c(n1,n5);
  c.nouvellePartie();

 
 // n1.attack();
 // n2.attack();
  //n3.attack();
  //n4->attack();

 return 0;
}