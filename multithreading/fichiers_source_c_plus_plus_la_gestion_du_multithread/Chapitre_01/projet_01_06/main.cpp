#include <iostream>
#include <thread>

void unefonction() {
   std::cout <<" thread en cours "<<std::endl;
}

class thread_raii : std::thread {
public:
    using thread::thread;

    ~thread_raii() { if(joinable()) join(); };
};

int main() {

    std::cout <<" debut du main "<<std::endl;

    thread_raii t1(unefonction);

    //t1.join();

    std::cout<<" fin du main "<<std::endl;

    return 0;
}
