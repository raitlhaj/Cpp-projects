#include <iostream>
#include<thread>

void unefonction() {

    std::cout <<" le thread fonctionne "<<std::endl;
}

int main() {

    std::thread t1(unefonction);

    std::cout <<std::boolalpha<<" t1 joignable ? "<<t1.joinable()<<std::endl;

    //t1.detach();

    std::thread t2(std::move(t1));
    t2.join();

    std::cout <<std::boolalpha<<" t1 joignable ? "<<t1.joinable()<<std::endl;

   // t1.join();

   // t1.~thread();

    std::cout <<" fin du main"<<std::endl;

return 0;
}
