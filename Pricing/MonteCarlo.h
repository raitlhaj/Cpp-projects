#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H
#include<vector>

class MonteCarlo
{
 private:
    int N,T;
    Option option;
    double eps, pi2;
 public:
    MonteCarlo();
    MonteCarlo(int ,Option );
    std::vector<double> boxmuller();
    double S(int );
    double price( );   
    void affiche();
};
#endif //MONTE_CARLO_H
