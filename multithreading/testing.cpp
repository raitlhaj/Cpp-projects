#include<future>
#include<iostream>

int somme(int debut, int fin)
{
  int reval=0;
  for(auto i=debut;i<fin;i++) reval+=i;
  return reval;
}


int main()
{
  std::cout<<std::endl<<" debut main: "<<std::endl;

  auto f1=std::async(somme,1,51);
  auto f2=std::async(somme,51,100);
  auto f3=std::async(somme,1,51);

  int v1=f1.get();



  
  int v2=f2.get();
  int v3=f3.get();
 int x=2,y=9;
 y=+x;

 std::cout<<y;
  std::cout<<std::endl<<" fin main: "<<v1<<" "<<v2<<" "<<v3<<std::endl;

    return 0;
}