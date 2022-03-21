#include <future>
#include <iostream>

int fonction1 (int i) {
    std::cout <<" ceci est la fonction "<<i<<std::endl;
    if( i==6)  throw std::runtime_error("oups");
    return i;
}

int main() {

    std::packaged_task<int(int)> tache1(fonction1);

    tache1(6);

    std::future<int> f1 = tache1.get_future();

 try {
    int valeur = f1.get();

    std::cout <<" valeur "<<valeur<< std::endl;
 }
 catch(std::exception& e) {
    std::cout <<"exception "<<e.what()<<std::endl;
 }

return 0;
}
