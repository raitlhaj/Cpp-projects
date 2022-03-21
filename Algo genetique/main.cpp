#include<iostream>
#include<random>
#include<memory>
#include <bitset>
#include<time.h>
#include"../Proba/Law.cpp"
#include<array>
#include<string>
#include<fstream>
#include<chrono>
#include <bits/stdc++.h>

class AlgoGen
{
    private:
    int N=0;
    int *pop=nullptr,*son=nullptr,*daugther=nullptr;
    std::string *popBin=nullptr,*motherBin=nullptr,*fatherBin=nullptr;
    double* myPrb=nullptr;
    std::vector<int> cnewpop,mnewpop,enewpop,father,mother;
    std::vector<double> fnewpop;

    public:
    AlgoGen(int N)
    {   this->N=N;
        pop=new int[N];
        daugther=new int[N/2];
        son=new int[N/2];
        popBin=new std::string[N];
        fatherBin=new std::string[N/2];
        motherBin=new std::string[N/2];
        myPrb=new double[N];
    }

    ~AlgoGen(){  delete(pop),delete(daugther),delete(son),delete(popBin),delete(fatherBin),delete(motherBin),delete(myPrb);}
    void myPop()
    {   
        srand(time(NULL));
        for (int i=0;i<N;i++)
        {   
            pop[i]=rand()%10;
            popBin[i]=std::bitset<8>(pop[i]).to_string();  
        }
    }
    void affiche()
    { 
        std::ofstream of;
        of.open("AlgoGenetique.dat");
        //Generation de la population intiale
        std::cout<<"Generation de la population intiale:"<<std::endl;
        of<<"Generation de la population intiale:"<<std::endl;
        for (int i=0;i<N;i++){std::cout<<" "<<pop[i],of<<" "<<pop[i];}
        std::cout<<std::endl<<std::endl;
        of<<std::endl<<std::endl;

        //Codage binaire de la pop
        std::cout<<"Codage binaire de la pop:"<<std::endl;
        of<<"Codage binaire de la pop:"<<std::endl;
        for (int i=0;i<N;i++){std::cout<<" "<<popBin[i],of<<" "<<popBin[i];}
        std::cout<<std::endl<<std::endl;
        of<<std::endl<<std::endl;
        //Selection des parents : father+ mother 
        std::cout<<"Selection des parents : father+ mother:"<<std::endl;
        of<<"Selection des parents : father+ mother:"<<std::endl;
        std::cout<<"Father: "<<std::endl;
        of<<"Father: "<<std::endl;
        for (int i=0;i<father.size();i++){std::cout<<" "<<father[i],of<<" "<<father[i];}
        std::cout<<std::endl<<"Mother: "<<std::endl;
        of<<std::endl<<"Father: "<<std::endl;
        for (int i=0;i<mother.size();i++){std::cout<<" "<<mother[i],of<<" "<<mother[i];}

        std::cout<<std::endl<<std::endl;
        of<<std::endl<<std::endl;
        //Results:-> croisement (pb)+Mutation(pm)+elite(solution)
        std::cout<<"Results:-> croisement(pb):"<<std::endl;
        of<<"Results:-> croisement(pb):"<<std::endl;
        for (int i=0;i<cnewpop.size();i++){std::cout<<" "<<cnewpop[i],of<<" "<<cnewpop[i];} 
        std::cout<<std::endl<<std::endl;
        of<<std::endl<<std::endl;

         std::cout<<"Results:->Mutation(pm):"<<std::endl;
        of<<"Results:->Mutation(pm):"<<std::endl;
        for (int i=0;i<mnewpop.size();i++){std::cout<<" "<<mnewpop[i],of<<" "<<mnewpop[i];} 
        std::cout<<std::endl<<std::endl;
        of<<std::endl<<std::endl;

         std::cout<<"Results:->Elites(solution sorted):"<<std::endl;
        of<<"Results:->Elites(solution sorted):"<<std::endl;
        for (int i=0;i<enewpop.size();i++){std::cout<<" "<<enewpop[i],of<<" "<<enewpop[i];} 
        std::cout<<std::endl<<std::endl;
        of<<std::endl<<std::endl;

        std::cout<<"Solution optimale:"<<enewpop[0]<<std::endl;
        of<<"Solution optimale:"<<enewpop[0]<<std::endl;

    }
  
    void prb()
    {
        double cum=0;

        for (int i=0;i<N;i++) cum+=f(pop[i]);
        myPrb[0]=f(pop[0])/cum;
        for (int i=1;i<N;i++)
         myPrb[i]=myPrb[i-1]+f(pop[i])/cum;
    }
    double f(int x){ return abs(exp(x*x));}
    void parentSelection()
    {   int i=0,k=0,l=0;
        double u=0;
        
    
        while (i<N)
         {
            u=uniform();
            if(u<myPrb[i] ){ father.push_back(pop[i]);}
    
            u=uniform();
            if(u<myPrb[i]){mother.push_back(pop[i]);}
            i++;
          }
       i=0,k=0;
    } 

    void croise(int i, int I)
    {
      int k=0,l=0;
      std::string sonBin="",daugtherBin="";

      for (int k=0;k<I;k++)
 	  { 
       sonBin.push_back(fatherBin[i][k]);
 	   daugtherBin.push_back(motherBin[i][k]);
      } 
      for (int k=I;k<8;k++)
 	  { 
        sonBin.push_back(motherBin[i][k]);
        daugtherBin.push_back(fatherBin[i][k]);
      } 
      cnewpop.push_back( std::bitset<8>(sonBin).to_ulong());
      cnewpop.push_back( std::bitset<8>(daugtherBin).to_ulong());
    }
	     
    void croisement(double pc=0.6)
    {  
        int k=0,l=0;
        for (int i=0;i<N/2;i++)
        {   double u=0;

            u=uniform();
            fatherBin[i]=std::bitset<8>(father[i]).to_string();
            motherBin[i]=std::bitset<8>(mother[i]).to_string();

            if(u<pc){croise(i,(int)(uniform()*10));}
        }
    }

    void mutation(double pm=0.01)
    {  
        int k=0,l=0,Im=0;
        double u=0.0;
        std::string str;
        mnewpop=cnewpop;

            for (int i=0;i<mnewpop.size();i++)
            {   u=uniform();
               
                if(u<pm)
                    {
                        Im=(int)(uniform()*10);
                        str=std::bitset<8>(mnewpop[i]).to_string();

                        if(str[Im]=='1')
                        str[Im]='0';
                        else str[Im]='1';
                    
                        mnewpop[i]= std::bitset<8>(str).to_ulong();
                    }
            } 
    }


    void ellite()
    {
        std::vector<std::vector<double>> vec;
        std::vector<std::vector<double>> matrix(mnewpop.size(), std::vector<double>(2, 0.0));


        for(int i=0;i<mnewpop.size();i++)
        {
            matrix[i][0]=mnewpop[i];
            matrix[i][1]=f(mnewpop[i]);
        }
        sortrows(matrix,1);
    
        for(int i=0;i<mnewpop.size();i++){enewpop.push_back(matrix[i][0]);}
    }

    void sortrows(std::vector<std::vector<double>>& matrix, int col) {    
        std::sort(matrix.begin(),
                matrix.end(),
                [col](const std::vector<double>& lhs, const std::vector<double>& rhs) {
                    return lhs[col]< rhs[col];
                });
    }

};


int main()
{
    clock_t start, end;
    start = clock();
//body
    int N=100;
    AlgoGen gen(N);
    
    gen.myPop();
    gen.prb();
    //gen.affiche();
    // std::cout<<std::endl<<std::endl<<std::endl;
    gen.parentSelection();
    gen.croisement();
    gen.mutation();
    gen.ellite();

    gen.affiche();
// end body
    end = clock();

    double duration_sec = double(end-start)/CLOCKS_PER_SEC;
    std::cout<<"duration_exec:"<<duration_sec<<"\n";
   // gen.scores();
   // gen.parents(1,0.9)[0];
    //std::string Binary = std::bitset<8>(18).to_string(); //to Binary
    //std::cout<<Binary<<"\n";
    //unsigned long decimal = std::bitset<8>(Binary).to_ulong();
    //std::cout<<decimal<<"\n";

return 0;
}