#include "carre.hpp"


Carre::Carre(double longueur, point p)
    :Rectangle(longueur,longueur,p)
{

}

Carre::~Carre(){
    //Nothing to do 
}   


ostream& operator<<(ostream& s, Carre const&carre){
    s <<"("<<"Type : Carre , longueur : "<< carre.getLongueur() << ")";
    return s;
}
