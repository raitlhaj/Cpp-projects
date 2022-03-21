#include <iostream>

#include <thread>

void une_fonction() {
    for( int i=0; i<100; i++) {
        std::cout <<"salut le thread "<<std::endl;
    }
}

int main() {

std::thread t1(une_fonction);
//constructeur par défaut : faire un move plus tard
std::thread t2;

//constructeur de move
std::thread t3(std::move(t1));



for (int i=0; i<10000; i++){
    std::cout <<"fin du main "<<std::endl;
}

return 0;
}
