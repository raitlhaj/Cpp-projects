#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>

class MyClass{
    public:
    MyClass();
    MyClass(int a, int b);
    ~MyClass();
    std::string affiche();
    int getReg();
    int getCons();

    private:
     int regVar;
     const int constVar;

    protected:
};


#endif //MYCLASS_H