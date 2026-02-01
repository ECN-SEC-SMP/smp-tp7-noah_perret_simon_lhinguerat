#ifndef CARRE_H
#define CARRE_H

#include "ostream"
#include "rectangle.hpp"

using namespace std;


class Carre : Rectangle {
private:

protected:
    
    
public:

    /**
     * @brief Create a Rectangle at origin of p
     * 
     */
    Carre(int longueur, point p);

    
    /**
     * @brief Destroy the Forme object
     * 
     */
    ~Carre();


};

#endif // CARRE_H


ostream& operator<<(ostream&, Carre const&carre);
