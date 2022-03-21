#include <thread>
#include <iostream>

class ClasseAProbleme {

    static thread_local int valeur;
public:
    static void set_valeur(int v) { valeur=v;}
    static int get_valeur() { return valeur;}
    //..
};
int thread_local ClasseAProbleme::valeur=0;

void unefonction(int v) {
    std::thread::id variable_locale = std::this_thread::get_id();
    std::chrono::seconds duree(v);
    //...
    std::cout <<" thread " <<std::this_thread::get_id()<<" positionne valeur "<<v<<std::endl;
    ClasseAProbleme::set_valeur(v);
    std::this_thread::sleep_for(duree);
    std::cout <<" thread " <<std::this_thread::get_id()<<" recupere valeur "<<ClasseAProbleme::get_valeur()<<std::endl;

    std::this_thread::sleep_for(duree);
    std::cout <<" thread " <<std::this_thread::get_id()<< " variable locale "<<variable_locale<<std::endl;
}

int main() {
 std::chrono::seconds duree(2);
std::thread t1(unefonction,3);
std::this_thread::sleep_for(duree);
std::thread t2(unefonction,6);

t1.join();
t2.join();

std::cout <<" fin du main "<<std::endl;

return 0;
}
