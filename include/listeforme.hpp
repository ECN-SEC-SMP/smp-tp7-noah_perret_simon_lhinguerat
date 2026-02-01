#include "carre.hpp"
#include "cercle.hpp"
#include "rectangle.hpp"

#include <iostream>
#include <vector>

using namespace std;

class ListeForme {
    private : 
        vector<Forme*> _listeForme;
    public:
    
    
    ListeForme();

    ~ListeForme();

    void addForme(Forme* f);

    void suprForme(unsigned int nb);

    Forme * getForme(unsigned int nb);
    
    double surface();

    Rectangle boite();

};
