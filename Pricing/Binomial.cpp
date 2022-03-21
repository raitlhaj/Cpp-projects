#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

class Binomial
{
    private:
    int T;
    double S0,u,d,r;


    protected:
    public:

    vector <vector<double>> spot,intrinsec,tree;
//constructor
    Binomial(int S,int Ti,double freeRate,double rateU,double rateD)
    {
          T=Ti; S0=S;u=rateU;d=rateD; r=freeRate;
          tree.resize(2*T-1,vector<double>(T));
          spot.resize(2*T-1,vector<double>(T));
          intrinsec.resize(2*T-1,vector<double>(T));

         for (int i = 0; i < 2*T-1; i++)
         for (int j = 0; j < T; j++)
              spot[i][j]=0,tree[i][j]=0,intrinsec[i][j]=0;       
    }
//Tree construction
    void constructTree()
    {
        spot[T-1][0]=S0;

        for (int j = 1; j < T; j++)
        for (int i =0 ; i < 2*T-1; i++)
        {
              if(i<T)
              spot[i][j]=spot[i+1][j-1]*(1+u);
              if(i>=T)
              spot[i][j]=spot[i-1][j-1]*(1+d);
        } 
        
    }

    void myOption(string ty,char way,double stike )
    {
       double q=(u-r)/(u-d);
      //intrinsec values

        for (int j=1; j<T; j++)
        for (int i=0 ; i<2*T-1; i++)
        {
          if( spot[i][j])
          intrinsec[i][j]= max(((way=='C')?1:-1)*(spot[i][j]-stike),0.0);
        }

        if( ty=="EU")
        {  //payoff calculation :
         for (int i =0; i < 2*T-1; i++)
         if( spot[i][T-1])
         tree[i][T-1]= max(((way=='C')?1:-1)*(spot[i][T-1]-stike),0.0);
    
            for (int j=T-1;j>=0;j--)
            for (int i=1;i<2*T-2;i++)
            {       
                    if( spot[i][j-1])
                    tree[i][j-1]= (1/(1+r))*(q*tree[i-1][j]+(1-q)*tree[i+1][j]);     
            } 
       }else 
       {
           for (int j=T-1;j>=0;j--)
           for (int i=1;i<2*T-2;i++)
            {       
                    if( spot[i][j-1])
                    tree[i][j-1]= (1/(1+r))*max(q*tree[i-1][j]+(1-q)*tree[i+1][j], intrinsec[i][j-1]);     
            } 
       }    
    }

  //show the tree  
    void affiche()
    {
        fstream ftree,fspot;
        ftree.open("C:/Users/ait_l.LAPTOP-6NFPIMOP/Dropbox/Working/C++/Data/treeFile.dat",ios::app);
        fspot.open("C:/Users/ait_l.LAPTOP-6NFPIMOP/Dropbox/Working/C++/Data/spotFile.dat",ios::app);

        for (int i = 0; i < 2*T-1; i++)
        {
               cout<<"\n";
               fspot<<endl;
          for (int j = 0; j < T; j++)
          {
              if((spot[i][j]))
              { cout<<" "<<spot[i][j];
               fspot<<" "<<spot[i][j];}
              else {
               cout<<"     ";
               fspot<<"     ";}
          }
        } 

        cout<<"\n\n";
        for (int i = 0; i < 2*T-1; i++)
        {
            cout<<"\n";
            ftree<<endl;
          for (int j = 0; j < T; j++)
          {
              if(tree[i][j] || spot[i][j])
               { cout<<" "<<tree[i][j];
              ftree<<" "<<tree[i][j];}
              else {
              cout<<"         ";
              ftree<<"         ";}
          }
        } 
    }
};


