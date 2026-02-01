#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ostream"
#include "forme.hpp"

using namespace std;


class Rectangle : Forme {
private:

protected:
    int _largeur, _longueur;
    
public:

    /**
     * @brief Create a Rectangle at origin of p
     * 
     */
    Rectangle(int longueur, int largeur, point p);

    
    /**
     * @brief Destroy the Forme object
     * 
     */
    ~Rectangle();

    /**
     * @brief Get the Longueur object
     * 
     * @return int 
     */
    virtual int getLongueur() const;

    /**
     * @brief Get the Largeur rectangle
     * 
     * @return int 
     */
    int getLargeur() const;

    /**
     * @brief Set the Longueur rectangle
     * 
     * @param NewL
     */
    virtual void setLongueur(int NewL);


    /**
     * @brief Set the Largeur rectangle
     * 
     * @param NewL
     */
    void setLargeur(int NewL);

   
    /**
     * @brief 
     * 
     * @return double 
     */
    virtual double perimetre();   

    /**
     * @brief 
     * 
     * @return double 
     */
    virtual double surface(); 
};

#endif // RECTANGLE_H


ostream& operator<<(ostream&, Rectangle const&rect);
