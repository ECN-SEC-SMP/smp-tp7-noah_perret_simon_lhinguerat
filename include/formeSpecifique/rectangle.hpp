#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ostream"
#include "forme.hpp"

using namespace std;


class Rectangle : public Forme {
private:

protected:
    double _largeur, _longueur;
    
public:

    /**
     * @brief Create a Rectangle at origin of p
     * 
     */
    Rectangle(double longueur, double largeur, point p);

    
    /**
     * @brief Destroy the Forme object
     * 
     */
    ~Rectangle();

    /**
     * @brief Get the Longueur object
     * 
     * @return double 
     */
    double getLongueur() const;

    /**
     * @brief Get the Largeur rectangle
     * 
     * @return double 
     */
    double getLargeur() const;

    /**
     * @brief Set the Longueur rectangle
     * 
     * @param NewL
     */
    void setLongueur(double NewL);


    /**
     * @brief Set the Largeur rectangle
     * 
     * @param NewL
     */
    void setLargeur(double NewL);

   
    /**
     * @brief 
     * 
     * @return double 
     */
    virtual double perimetre();   

    /**
     * @brie
     * 
     * @return double 
     */
    virtual double surface(); 
};

#endif // RECTANGLE_H


ostream& operator<<(ostream&, Rectangle const&rect);
