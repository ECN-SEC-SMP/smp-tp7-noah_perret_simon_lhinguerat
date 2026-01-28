#include "../include/class.hpp"


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


const int::getX(){
    return 
}
