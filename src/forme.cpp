#include "forme.hpp"



Forme::Forme(point p){
    //_centre.setXandY(p.getX(),p.getY());
    _centre = p;
}


Forme::~Forme(){
    //Nothing to do;
}

int Forme::getOriginX() const{
    return _centre.getX();
}

int Forme::getOriginY() const{
    return _centre.getY();
}

void Forme::setOriginX(int NewX){
    _centre.setX(NewX);
}

void Forme::setOriginY(int NewY){
    _centre.setY(NewY);
}

void Forme::setOriginXY(int NewX,int NewY){
    _centre.setXandY(NewX,NewY);
}

void Forme::translater(point &p){
    _centre.setX(_centre.getX()+p.getX());
    _centre.setY(_centre.getY()+p.getY());
    //_centre.setXandY(_centre.getX()+p.getX(),_centre.getY()+p.getY());
}

void Forme::operator+=(point const&p){
    _centre.setXandY(p.getX(),p.getY());
}

ostream& operator<<(ostream& s, Forme const&form){
    s <<"("<<form.getOriginX()<< ":" << form.getOriginY() << ")";
    return s;
}


