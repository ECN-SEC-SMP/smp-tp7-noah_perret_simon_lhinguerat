#include "cercle.hpp"


Cercle::Cercle(point p, int r)
    :Forme(p)
{
    _rayon = r;
}

Cercle::~Cercle(){

}

int Cercle::getRayon() const{
    return _rayon;
}

    
void Cercle::setRayon(int NewR){
    _rayon = NewR;
}

    
double Cercle::perimetre(){
    return 2*PI*_rayon;
}  

double Cercle::surface(){
    return PI*_rayon*_rayon;
}


ostream& operator<<(ostream& s, Cercle const&cercl){
    s <<"("<<"Type : Cercle , origine : "<< "("<<cercl.getOriginX()<<":"<<cercl.getOriginY()<<")"
      << ",rayon : "<< cercl.getRayon() <<")";
    return s;
}