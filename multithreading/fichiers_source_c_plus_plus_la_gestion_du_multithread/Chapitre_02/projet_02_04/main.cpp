#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

std::timed_mutex verrou;

void production() {
    for( int i=0; i<10; i++) {

        verrou.lock();

        std::cout <<" production des donnees ... "<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(950));

        verrou.unlock();
    }

}

void miseajour() {
    for( int i=0; i<10; i++) {
        if(verrou.try_lock_for(std::chrono::milliseconds(800))) {
            std::cout <<" recuperation des nouvelles donnees"<<std::endl;
            verrou.unlock();

        }
        else {
            std::cout <<" continue avec les donnes existantes "<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

    }
}



int main() {

    std::thread t1(production);
    std::thread t2(miseajour);

    t1.join();
    t2.join();

return 0;
}
