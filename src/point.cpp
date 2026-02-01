#include "point.hpp"

point::point() : _x(0),_y(0){   
}

point::point(int x, int y){
    _x = x;
    _y = y;
}

point::point(const point &p){
    _x = p._x;
    _y = p._y;
}

point::~point(){
    //nothing to do
}

void point::translater(const point  &p){
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


