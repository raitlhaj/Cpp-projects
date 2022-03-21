
#include <iostream>
#include <thread>

void unefonction(int& v) {
        v=6;
        std::cout <<" salut le thread valeur : "<<v<<std::endl;
}

int main() {

int valeur=4;

std::cout<<" valeur avant "<<valeur<<std::endl;
std::thread t1{unefonction,std::ref(valeur)};

std::cout<<"attente dans le main "<<t1.get_id()<<std::endl;

char c;
std::cin>>c;
std::cout<<" valeur apres "<<valeur<<std::endl;
return 0;
}
