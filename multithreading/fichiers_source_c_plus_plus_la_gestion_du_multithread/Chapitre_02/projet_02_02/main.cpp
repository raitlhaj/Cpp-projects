#include <thread>
#include <iostream>
#include <mutex>

std::recursive_mutex verrou;


int appel_recursif(int v) {
    int retval=0;

    verrou.lock();
    if(v==0) retval=0;
    else retval=v+appel_recursif(v-1);
    verrou.unlock();

    return retval;
}

void fonction() {
    std::cout <<"entree dans la fonction"<<std::endl;
    int total = appel_recursif(5);
    std::cout<<"valeur : "<<total<<std::endl;
}


int main() {

    std::thread t1(fonction);

    t1.join();

return 0;
}
