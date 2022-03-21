#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

#include <condition_variable>

std::mutex verrou;
std::condition_variable cond;
bool donnee=false;

void production() {
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::unique_lock<std::mutex> lck(verrou);
    std::cout <<" la production commence ..."<<std::endl;
    donnee=true;
    cond.notify_one();
}

void consommation() {

    std::cout<<" consommation ?"<<std::endl;

    std::unique_lock<std::mutex> lck(verrou);
    cond.wait(lck,[] { return donnee==true;});
    std::cout<<" consommation peut commencer ..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<" la consommation va finir ..."<<std::endl;

}

int main() {
    std::thread t1(production);
    std::thread t2(consommation);

    t1.join();
    t2.join();

return 0;
}
