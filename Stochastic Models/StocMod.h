//class Action
class Action
{

private:
double volatility;
double rate;
int T;
double price0;

public:
Action();
Action(double,double,double,int);
void affiche();
double getPrice0(){return price0;};

};


//Class option

class Option
{
private:
Action action;
double strike;

public:
Option(Action,double);
void affiche();

};
