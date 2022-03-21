#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

std::timed_mutex verrou;
std::timed_mutex autre_verrou;

void production () {

  for( int i=0; i<10; i++) {

    //verrou.lock();
    //autre_verrou.lock();
    //remplacé par
    std::lock(verrou, autre_verrou);

    std::lock_guard<std::timed_mutex> lck(verrou, std::adopt_lock);
    std::lock_guard<std::timed_mutex> lck2(autre_verrou, std::adopt_lock);

    std::cout <<"production... "<<std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(950));
   // verrou.unlock();
  }
}

void miseajour() {
 for( int i=0; i<10; i++) {
        if(verrou.try_lock_for(std::chrono::milliseconds(800))) {
            std::cout <<"recuperation de nouvelles donnees"<<std::endl;

            verrou.unlock();
        }
        else {
            std::cout <<" continue comme d'hab"<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

int main() {

    std::thread t1(production);
    std::thread t2(miseajour);

    t1.join();
    t2.join();
}
