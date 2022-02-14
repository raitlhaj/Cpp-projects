#include<iostream>
using namespace std;
class Rectangle
{
	private:
	 double	largeur;
	 double hauteur;

	public:
	 Rectangle(double largeur, double hauteur)
	 {
	  this->largeur=largeur;
	  this->hauteur=hauteur;
	 }

	double surface()
	 {
		 return largeur*hauteur;
	 }

	void affiche()
	{
		cout << "RECTANGLE ["<<largeur<<";"<<hauteur<<"]"<<endl;
	}
};

class RectangleColore: public class Rectangle
{
	private:
		string couleur;
        public:

        RectangleColore(double l, double h, string col):Rectangle(l,h), string(col)
	{
	}
};
main()
{
	Rectangle rect(2.5,3.6);
	rect.affiche();
}
