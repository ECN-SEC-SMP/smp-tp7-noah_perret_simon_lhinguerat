#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ostream"
#include "forme.hpp"

using namespace std;

#define PI 3.14


class Cercle : public Forme Forme {
private:

protected:
    int _rayon;
    
public:

    Cercle(point p, int r);

    ~Cercle();

    int getRayon() const;

    void setRayon(int NewR);

    double perimetre();   

    double surface(); 
};

#endif // CERCLE_H


ostream& operator<<(ostream&, Cercle const&cercl);