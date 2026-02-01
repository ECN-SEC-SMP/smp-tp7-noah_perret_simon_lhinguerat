#ifndef FORME_H
#define FORME_H

#include "point.hpp"

class Forme {
private:

protected:
    point _centre;
    
public:

    /**
     * @brief Create a forme at origin
     * 
     */
    Forme(point p);

    
    /**
     * @brief Destroy the Forme object
     * 
     */
    ~Forme();

    /**
     * @brief moove the forme
     * 
     * @param p 
     */
    void translater(point &p);
    
    /**
     * @brief Get the Origin X object
     * 
     * @return int 
     */
    int getOriginX() const;

     /**
      * @brief Get the Origin Y object
      * 
      * @return int 
      */
    int getOriginY() const;

    /**
     * @brief set the Origin X object
     * 
     * @param NewX 
     */
    void setOriginX(int NewX);

    /**
     * @brief set the Origin Y object
     * 
     * @param NewY 
     */
    void setOriginY(int NewY);

    /**
     * @brief Set the Origin X,Y object
     * 
     * @param NewX 
     * @param NewY 
     */
    void setOriginXY(int NewX,int NewY);

    //méthodes abstraite
    virtual double perimetre() = 0;   

    virtual double surface() = 0; 
};

#endif // FORME_H