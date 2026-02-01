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
    if (_listeForme.size() <= nb) return;  
    
    //On  suprimme
    delete _listeForme[nb];

    //On l'enlève de la liste
    _listeForme.erase(_listeForme.begin() + nb);
}

Forme * ListeForme::getForme(unsigned int nb){
    //On vérifie que la forme existe
    if (_listeForme.size() < nb) return nullptr;  

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

// Rectangle ListeForme::boite(){
//     // Cas liste vide
//     if (_listeForme.empty()){
//         return Rectangle(0, 0, point(0,0));
//     }

//     double LongeurBoite = 0;
//     double LargeurBoite = 0;
    

//     for (Forme* f : _listeForme){
//         if (!f) continue;

//         double fMinX, fMaxX, fMinY, fMaxY;

//         // Rectangle (et Carre, car Carre hérite de Rectangle)
//         if (auto r = dynamic_cast<Rectangle*>(f)){

//             LongeurBoite += r->getLongueur() ; // demi-longueur
//             if(LargeurBoite < r->getLargeur())LargeurBoite =r->getLargeur();
//         }
//         // Cercle
//         else if (auto c = dynamic_cast<Cercle*>(f)){
//             LongeurBoite  += (c->getRayon())*2;

//             if(LargeurBoite < (c->getRayon())*2)LargeurBoite =(c->getRayon())*2;
            
//         }
//         else {
//             // Forme inconnue: soit tu ajoutes un calcul,
//             // soit tu ignores, soit tu throw. Ici on ignore.
//             continue;
//         }

//     }

// }

Rectangle ListeForme::boite() {
    if (_listeForme.empty()) return Rectangle(0, 0, point(0, 0));

    // On initialise avec des valeurs extrêmes
    double minX = 1e30, maxX = -1e30, minY = 1e30, maxY = -1e30;

    for (Forme* f : _listeForme) {
        if (!f) continue;

        double currentMinX, currentMaxX, currentMinY, currentMaxY;

        if (auto r = dynamic_cast<Rectangle*>(f)) {
            // Un rectangle est centré sur son point : limites = centre +/- (dimension/2)
            currentMinX = r->getOriginX() - (r->getLongueur() / 2.0);
            currentMaxX = r->getOriginX() + (r->getLongueur() / 2.0);
            currentMinY = r->getOriginY() - (r->getLargeur() / 2.0);
            currentMaxY = r->getOriginY() + (r->getLargeur() / 2.0);
        } 
        else if (auto c = dynamic_cast<Cercle*>(f)) {
            // Un cercle : limites = centre +/- rayon
            currentMinX = c->getOriginX() - c->getRayon();
            currentMaxX = c->getOriginX() + c->getRayon();
            currentMinY = c->getOriginY() - c->getRayon();
            currentMaxY = c->getOriginY() + c->getRayon();
        } 
        else continue;

        // Mise à jour des bornes globales de la liste
        if (currentMinX < minX) minX = currentMinX;
        if (currentMaxX > maxX) maxX = currentMaxX;
        if (currentMinY < minY) minY = currentMinY;
        if (currentMaxY > maxY) maxY = currentMaxY;
    }

    // Calcul des dimensions finales de la boîte
    double largeurBoite = maxX - minX;
    double hauteurBoite = maxY - minY;
    point centreBoite(minX + largeurBoite / 2.0, minY + hauteurBoite / 2.0);

    // INDISPENSABLE : Le return final pour éviter le crash
    return Rectangle(largeurBoite, hauteurBoite, centreBoite);
}