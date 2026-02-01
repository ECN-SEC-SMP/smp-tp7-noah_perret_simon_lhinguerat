#ifndef CARRE_H
#define CARRE_H

#include "ostream"
#include "rectangle.hpp"

using namespace std;


class Carre :public Rectangle {
private:

protected:
    
    
public:

    /**
     * @brief Create a Carre at origin of p
     * 
     */
    Carre(double longueur, point p);

    
    /**
     * @brief Destroy the Carre object
     * 
     */
    ~Carre();


};

#endif // CARRE_H


ostream& operator<<(ostream&, Carre const&carre);
