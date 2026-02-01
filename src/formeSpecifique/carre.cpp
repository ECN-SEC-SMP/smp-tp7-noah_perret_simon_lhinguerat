#include "carre.hpp"


Carre::Carre(int longueur, point p)
    :Rectangle(longueur,longueur,p)
{

}



ostream& operator<<(ostream& s, Rectangle const&rect){
    s <<"("<<"Type : Carre , longueur : "<< rect.getLongueur() << ")";
    return s;
}
