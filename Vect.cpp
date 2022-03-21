#include <iostream>
#include<vector>
#include<list>
#include<algorithm> //STL



int main () {


std::list<int> v0={5,8,6,4,3,6,9};
std::vector<int> v1={5,8,6,4,3,6,9};

std::vector<int> v2;

//algo  modifiants
v0.sort();
//std::sort(v1.begin(),v1.end());
std::sort(v1.begin(),v1.end(),std::greater<int>());
std::for_each(v1.begin(),v1.end(),[](int v){std::cout<<v<<std::endl;});

//find & find_if
std::cout<<std::endl<<*(std::find(v1.begin(),v1.end(),6));

std::cout<<std::endl<<*(std::find_if(v1.begin(),v1.end(),[](int v){return v>7;}));
std::cout<<std::endl<<std::binary_search(v1.begin(),v1.end(),6);  // s'applique sur un conteneur trier




return 0;
}
