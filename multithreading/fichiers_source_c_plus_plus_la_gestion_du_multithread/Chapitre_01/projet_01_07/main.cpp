#include <thread>
#include <iostream>
#include <chrono>

void unefonction() {
    std::cout<<"thread en cours "<<std::this_thread::get_id()<<std::endl;

    std::chrono::seconds duree(3);

    std::this_thread::sleep_for(duree);

    std::cout <<" le thread va se terminer ..."<<std::endl;

    std::chrono::system_clock::time_point instant(std::chrono::system_clock::now()+duree);

    std::this_thread::sleep_until(instant);

    std::cout <<" le thread se termine ! "<<std::endl;

    std::this_thread::yield();
}

int main() {

    std::thread t1(unefonction);

    //std::cout <<" handle : "<< t1.native_handle()<<std::endl;

    t1.join();

    std::cout << "fin du main "<<std::this_thread::get_id()<<std::endl;

 return 0;
}
