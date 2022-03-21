#include<iostream>
#include<array>
#include<cassert>
#include<ctime>

using namespace std;
enum CouleurCase {VIDE,ROND,CROIX};
typedef array<array<CouleurCase,3>,3> Grille;
class JeuMorpion
{
  private:
  Grille grille;
  bool placer_coup(size_t ligne, size_t colonne, CouleurCase c)
  {
    if(ligne>grille.size()-1||colonne>grille[ligne].size()-1)
    {
      return false;
    }
    if( grille[ligne][colonne]==VIDE)
    {grille[ligne][colonne]=c;
    return true;}
    return false;
  }
  public:
  void initialise ()
  {
    for(auto &ligne :grille)
      for (auto &kcase:ligne)
      kcase=VIDE;
   }
  bool placer_rond(size_t ligne,size_t colonne)
  {
    return placer_coup(ligne,colonne,ROND);
  }
  bool placer_croix(size_t ligne,size_t colonne)
  {
    return placer_coup(ligne,colonne,CROIX);
  }


  bool partie()
  { 
  int i,j;
  srand(time(nullptr));
  //j1 & j2
  
  i=rand()%10;j=rand()%10;
  while(!checkGagnant())
  {
    while(!placer_croix(i,j)){i=rand()%10;j=rand()%10;}
    while(!placer_rond(i,j)){i=rand()%10;j=rand()%10;}
  }

  }

  bool checkGagnant()
  {

    if(
      (grille[0][0]==CROIX&&grille[1][1]==CROIX&grille[2][2]==CROIX)
      || (grille[0][2]==CROIX&&grille[1][1]==CROIX&grille[2][0]==CROIX)
      || (grille[0][0]==CROIX&&grille[1][0]==CROIX&grille[2][0]==CROIX)
      || (grille[0][1]==CROIX&&grille[1][1]==CROIX&grille[2][1]==CROIX)
      || (grille[0][2]==CROIX&&grille[1][2]==CROIX&grille[2][2]==CROIX)
      || (grille[0][0]==CROIX&&grille[0][1]==CROIX&grille[0][2]==CROIX)
      || (grille[1][0]==CROIX&&grille[1][1]==CROIX&grille[1][2]==CROIX)
      || (grille[2][0]==CROIX&&grille[2][1]==CROIX&grille[2][2]==CROIX)
    )
    { cout<<"\n Joueur 1 a gagne!";
      return true;}

      if(
      (grille[0][0]==ROND&&grille[1][1]==ROND&grille[2][2]==ROND)
      || (grille[0][2]==ROND&&grille[1][1]==ROND&grille[2][0]==ROND)
      || (grille[0][0]==ROND&&grille[1][0]==ROND&grille[2][0]==ROND)
      || (grille[0][1]==ROND&&grille[1][1]==ROND&grille[2][1]==ROND)
      || (grille[0][2]==ROND&&grille[1][2]==ROND&grille[2][2]==ROND)
      || (grille[0][0]==ROND&&grille[0][1]==ROND&grille[0][2]==ROND)
      || (grille[1][0]==ROND&&grille[1][1]==ROND&grille[1][2]==ROND)
      || (grille[2][0]==ROND&&grille[2][1]==ROND&grille[2][2]==ROND)
    ){ cout<<"\n Joueur 2 a gagne!";
      return true;}
   return false;
  }

  void showme(){
    for(auto &ligne:grille)
    {
       cout<<endl;
       for(auto &kcase:ligne)
       {
         switch(kcase){
         case CROIX:cout<<" C ";break;
         case VIDE: cout<<" V ";break;
         case ROND: cout<<" R ";break;
         default: cout<<" O ";
         }
       }
    
    }
   
  }
};
int main()
{ 
  JeuMorpion jeu;
  jeu.initialise();
  jeu.partie();
  cout<<endl;
  jeu.showme();
}
