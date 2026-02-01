#ifndef CERCLE_H
#define CERCLE_H

#include "ostream"
#include "forme.hpp"

using namespace std;

#define PI 3.14


class Cercle :public Forme {
private:

protected:
    double _rayon;
    
public:

    Cercle(point p, double r);

    ~Cercle();

    double getRayon() const;

    void setRayon(double NewR);

    double perimetre();   

    double surface(); 
};

#endif // CERCLE_H


ostream& operator<<(ostream&, Cercle const&cercl);