#include<math.h>
#include<random>
#include"Law.h"

const double eps=1.e-50, pi2 =8*atan(1);
double phi2(double x)
{
  int MAX_N=10000;
  double s=0.0,theta=10,sig=1.0,u=0.0;
  return (x<2)?0.5+(1/sqrt(2*3.14))*(x-pow(x,3)/6+pow(x,5)/40):(x>6)?1:0;

}

double phi1(double z)
{
// Approximation de la fonction de distribution cumulative normale (par des séries de Taylor)
// Fonction reprise du document de Bernt Arne Ødegaard
if (z > 6.0)
return 1.0; // éviter les valeurs illicites
if (z < -6.0)
return 0.0;
double b1 = 0.31938153;
double b2 = -0.356563782;
double b3 = 1.781477937;
double b4 = -1.821255978;
double b5 = 1.330274429;
double p = 0.2316419;
double c2 = 0.3989423;
double a=fabs(z);
double t = 1.0/(1.0+a*p);
double b = c2*exp((-z)*(z/2.0));
double n = ((((b5*t+b4)*t+b3)*t+b2)*t+b1)*t;
n = 1.0-b*n;
if ( z < 0.0 )
n = 1.0 - n;
return n;
}

double gauss(){return sqrt(eps-2.*log(eps+uniform()))*cos(uniform()*pi2);}
double uniform(){return rand()/(double)RAND_MAX;}