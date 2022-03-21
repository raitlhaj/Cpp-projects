#ifndef PILE_H
#define PILE_H
#include<vector>

template<typename T=int,typename conteneur= std::vector<T>,  typename U=int>
class Pile
{
    conteneur data;
    U index;

    public:
    Pile( T taille):index(0){ }
    void empile(T valeur)
    {
        data.push_back(valeur);
        index++;
    }
};



#endif

