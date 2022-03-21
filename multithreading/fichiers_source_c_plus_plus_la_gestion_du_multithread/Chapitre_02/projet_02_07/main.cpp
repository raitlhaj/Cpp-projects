#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

class classe_partagee {
    static std::chrono::system_clock::time_point tp0;
    static std::once_flag leflag;

public:
    static void init() {
        tp0 = std::chrono::system_clock::now();
        std::cout <<" init appele "<<std::endl;
    }

    classe_partagee(){
        std::call_once(leflag,init);
        // autre travail à réalisé
        std::cout <<" ctor appele "<<std::endl;
    }
};
std::chrono::system_clock::time_point classe_partagee::tp0;
std::once_flag classe_partagee::leflag;

void fonction() {
    classe_partagee cp;
    //...
}

int main() {

     std::thread t1(fonction);
     std::thread t2(fonction);

     t1.join();
     t2.join();

}
