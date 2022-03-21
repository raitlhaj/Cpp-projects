#include <thread>
#include <iostream>
#include <mutex>

class Ressource {
    std::mutex verrou;

public:
    void ecrire(int v) {
        for( int i=0; i<5; i++) {

        //verrou.lock();
        if(verrou.try_lock()) {

               std::cout<<"le thread "<<std::this_thread::get_id()<<" est en train d'ecrire"<<std::endl;
               verrou.unlock();
        }
        else {
             std::cout<<"le thread "<<std::this_thread::get_id()<<" impossible d'ecrire"<<std::endl;
        }

            std::this_thread::sleep_for(std::chrono::seconds(v));


        }
    }
    void lire (int v) {
     for( int i=0; i<5; i++) {

        verrou.lock();
            std::cout<<"le thread "<<std::this_thread::get_id()<<" est en train de lire"<<std::endl;
        verrou.unlock();

            std::this_thread::sleep_for(std::chrono::seconds(v));
        }
    }
};


void fonction(Ressource& res, int v){
    res.ecrire(v);
    res.lire(v);
}

int main() {

    Ressource res;

    std::thread t1(fonction, std::ref(res),1);
    std::thread t2(fonction, std::ref(res),2);

    t1.join();
    t2.join();
return 0;
}
