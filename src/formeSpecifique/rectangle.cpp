#include "rectangle.hpp"

Rectangle::Rectangle(double longueur, double largeur, point p)
    : Forme(p) // Appel du constructeur de la classe mère
{
    _longueur = longueur;
    _largeur = largeur;
}


Rectangle::~Rectangle(){
    //Nothing to do
}

double Rectangle::getLongueur() const{
    return _longueur;
}


double Rectangle::getLargeur() const{
    return _largeur;
}

void Rectangle::setLongueur(double NewL){
    _longueur = NewL;
}

void Rectangle::setLargeur(double NewL){
    _largeur = NewL;
}



double Rectangle::perimetre(){
    return 2 * (_largeur + _longueur);
} 


double Rectangle::surface(){
    return _largeur * _longueur;
} 


ostream& operator<<(ostream& s, Rectangle const&rect){
    s <<"("<<"Type : Rectangle , longueur : "<< rect.getLongueur()
      << ",largeur : "<< rect.getLargeur() <<")";
    return s;
}
