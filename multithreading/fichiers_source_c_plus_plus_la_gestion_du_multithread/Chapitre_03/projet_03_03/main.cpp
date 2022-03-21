#include <future>
#include <iostream>


int somme(int debut, int fin){
    int retval=0;

    for (int i=debut; i<fin; i++)
        retval+=i;

    return retval;
}

int main() {

//entre 1 et 100
std::cout <<" debut du main"<<std::endl;
//entre 1 et 51
auto f1=std::async(somme,1,51);
std::cout <<" apres f1"<<std::endl;
//entre 51 et 100
auto f2=std::async(somme,51,100);
std::cout <<" apres f2"<<std::endl;

int valeur = f1.get()+f2.get();

std::cout <<" valeur " <<valeur <<std::endl;

return 0;
}
