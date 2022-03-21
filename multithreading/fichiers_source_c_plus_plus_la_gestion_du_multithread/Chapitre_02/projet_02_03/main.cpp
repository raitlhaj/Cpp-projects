#include <thread>
#include <iostream>
#include <mutex>

void fonction() {

    std::mutex verrou;

    try {
        verrou.lock();
        verrou.lock();
        //...
        verrou.unlock();
    }
    catch(system_exception& exp) {
        verrou.unlock();
        std::cout<<exp.what()<<std::endl;
        std::cout<<exp.code()<<std::endl;
    }

}

int main() {

    //system_error
    std::thread t1(fonction);
    t1.join();

    std::thread t2(fonction);
    t2.join();

return 0;
}
