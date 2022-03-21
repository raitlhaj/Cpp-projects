#include <iostream>
#include <thread>

void unefonction1() {
    std::cout <<" ceci est le thread 1"<<std::endl;
}

void unefonction2() {
    std::cout <<" ceci est le thread 2"<<std::endl;
}


int main() {

std::cout <<" nb thread max "<<std::thread::hardware_concurrency()<<std::endl;

std::thread t1(unefonction1);
std::thread t2(unefonction2);

std::cout <<std::boolalpha<<" t1 est joignable ? "<<t1.joinable()<<std::endl;
std::cout <<" t2 est joignable ? "<<t2.joinable()<<std::endl;

t1.join();
t2.join();

std::cout <<" t1 est joignable ? "<<t1.joinable()<<std::endl;
std::cout <<" t2 est joignable ? "<<t2.joinable()<<std::endl;


std::cout <<" ceci est le thread principal"<<std::endl;

return 0;
}
