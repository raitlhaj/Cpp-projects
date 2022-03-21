#include <future>
#include <iostream>

void fonction1(int i) {
    std::cout <<"ceci est la tache num "<<i<<std::endl;
}

int fonction2(int i) {
    std::cout <<"ceci est la tache num "<<i<<std::endl;
    return i;
}

int main() {

    std::packaged_task<void(int)> tache1(fonction1);

    tache1(5);

    std::packaged_task<int(int)> tache2(fonction2);

    tache2(6);


    std::cout <<"fin du main"<<std::endl;

return 0;
}
