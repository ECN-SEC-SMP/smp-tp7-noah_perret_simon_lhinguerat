#include "listeforme.hpp"


ListeForme::ListeForme(){

}

ListeForme::~ListeForme(){

}

void ListeForme::addForme(Forme * f){
    _listeForme.push_back(f);
}

void ListeForme::suprForme(unsigned  int nb){
    //On vérifie que la forme existe
    if (_listeForme.size() < nb) return;  
    
    //On  suprimme
    delete _listeForme[nb];

    //On l'enlève de la liste
    _listeForme.erase(_listeForme.begin() + nb);
}

Forme * ListeForme::getForme(unsigned int nb){
    //On vérifie que la forme existe
    if (_listeForme.size() < nb) return;  

    return _listeForme[nb];
}


double ListeForme::surface(){
    double surfaceT =0.0;
    int taille = _listeForme.size();
    for(int i =0; i<taille; i++){
        surfaceT += _listeForme[i]->surface();
    }
    return surfaceT;
}

Rectangle ListeForme::boite(){
    // Cas liste vide
    if (_listeForme.empty()){
        return Rectangle(0, 0, point(0,0));
    }

    double LongeurBoite = 0;
    double LargeurBoite = 0;
    

    for (Forme* f : _listeForme){
        if (!f) continue;

        double fMinX, fMaxX, fMinY, fMaxY;

        // Rectangle (et Carre, car Carre hérite de Rectangle)
        if (auto r = dynamic_cast<Rectangle*>(f)){

            LongeurBoite += r->getLongueur() ; // demi-longueur
            if(LargeurBoite < r->getLargeur())LargeurBoite =r->getLargeur();
        }
        // Cercle
        else if (auto c = dynamic_cast<Cercle*>(f)){
            LongeurBoite  += (c->getRayon())*2;

            if(LargeurBoite < (c->getRayon())*2)LargeurBoite =(c->getRayon())*2;
            
        }
        else {
            // Forme inconnue: soit tu ajoutes un calcul,
            // soit tu ignores, soit tu throw. Ici on ignore.
            continue;
        }

    }

}

