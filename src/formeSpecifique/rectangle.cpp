#include "rectangle.hpp"

Rectangle::Rectangle(int longueur, int largeur, point p)
    : Forme(p) // Appel du constructeur de la classe mère
{
    _longueur = longueur;
    _largeur = largeur;
}


Rectangle::~Rectangle(){
    //Nothing to do
}

int Rectangle::getLongueur() const{
    return _longueur;
}


int Rectangle::getLargeur() const{
    return _largeur;
}

void Rectangle::setLongueur(int NewL){
    _longueur = NewL;
}

void Rectangle::setLargeur(int NewL){
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
