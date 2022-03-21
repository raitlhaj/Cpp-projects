#ifndef BS_PRICING_H
#define BS_PRICING_H
struct Action
{
    double volatility;
    double r;
    int T;
    double S0;
    Action();
    Action(double,double,double,int);
    void affiche();
};

//Class option
class Option 
{
private:
    Action stock;
    double strike,t;
    int e;
public:
    Option();
    Option(Action,double,int,double);
    double price();
    double BSformula();
    Action getStock();
    double gett();
    double getK();
    int getE();
    void affiche();
};

#endif // BS_PRICING_H