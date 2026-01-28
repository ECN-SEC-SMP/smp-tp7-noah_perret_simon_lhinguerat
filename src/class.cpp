#include "../include/class.hpp"
#include <iostream>
using namespace std;




point::point() : _x(0),_y(0)
{
    
}

point::point(int x, int y){
    _x = x;
    _y = y;
}

point::point(const point &p){
    _x = p._x;
    _y = p._y;
}

void point::translater(point &p){
    _x += p._x;
    _y += p._y;
}


 int point::getX() const{
    return _x;
}


int point::getY() const{
    return _y;
}
void point::setX(int NewX){
    _x=NewX;

}

void point::setY(int NewY){
    _y=NewY;
}

void point::setXandY(int NewX,int NewY){
    _x=NewX;
    _y=NewY;
}

void point::operator+=( point const&p){
    _x += p.getX();
    _y += p.getY();
}

ostream& operator<<(ostream&s,point const&p){
    s << "(" << p.getX() << ", " << p.getY() << ")";
    return s;
}


//rectangle :

rectangle::rectangle(){
    encrage = point();
    longueur = 2;
    largeur = 1;
}

rectangle::rectangle(point const& p, int L, int l){
    encrage = p;
    longueur = L;
    largeur = l;
}

int rectangle::getX(){return encrage.getX();}
int rectangle::getY(){return encrage.getY();}
int rectangle::getL(){return longueur;}
int rectangle::getl(){return largeur;}

void rectangle::operator+=( point const&p){
    encrage.setX(p.getX());
    encrage.setY(p.getY());
}

ostream& operator<<(ostream&s,point const&p){
    s << "(" << p.getX() << ", " << p.getY() << ")";
    return s;
}

ostream& operator<<(ostream&s,rectangle const&rect){
    s << "(" << rect.getX() << ", " << rect.getY() << ")";
    return s;
}