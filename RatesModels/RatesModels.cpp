#include <iostream>
#include<math.h>
using namespace std;

class ZC 
{
    private:
    double r;
    public:
    ZC(double re)
    {
        r=re;
    }
    double B(int t, int T)
    {
        return pow(1/(1+r),(T-t));
    }

    double R(int t, int T)
    {
        return -log(B(t,T))/(T-t);
    }
    double L(int t, int T)
    {
        return (1/B(t,T)-1)*(1/(T-t));
    }

     double Y(int t, int T)
    {
        return exp(-log(B(t,T))/(T-t))-1;
    }

    double forwardRate(int t, int S, int T)
    { 
        return (1/(double)(T-S))*(B(t,S)/B(t,T)-1);
    }
    double sumValue(int t0,int T)
    {
        double s=0.0;
        for (int i=t0+1;i<=T;i++)
         s +=B(t0,i);

      return s;
    }

};


int main()
{ 
    
    ZC z(0.03);
    
    cout<<"Taux ZC B(0,2): "<<z.B(0,2)<<"\n";
    cout<<"Taux E B(0,10): "<<z.sumValue(0,10)<<"\n";
    cout<<"Taux continuement compose R(0,2): "<<z.R(0,2)<<"\n";
    cout<<"Taux simplement compose L(0,2): "<<z.L(0,2)<<"\n";
    cout<<"Taux annuellement compose Y(0,2): "<<z.Y(0,2)<<"\n";
    cout<<"bound Bc(10): "<<z.sumValue(0,10)*10+100*z.B(0,10)<<"\n";
    cout<<"L(t,S,T) "<<z.forwardRate(0,3,6)<<" "<<z.B(0,3)<<" "<<z.B(0,6)<<"\n";

    
   
    
    return 0;
}
