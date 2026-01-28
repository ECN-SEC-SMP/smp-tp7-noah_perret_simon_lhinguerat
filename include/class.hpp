#ifndef CLASS_H
#define CLASS_H

class point {
public:

    /**
     * @brief Create a point at origin
     * 
     */
    point();

    /**
     * @brief Create a point at fice coordonate
     * 
     */
    point(int x, int y);


    /**
     * @brief Duplicate a point
     * 
     */
    point(const point &p);
    
    // Destructor
    ~point();

    // translater
    void translater(point &p);
    
    /**
     * @brief Get the Value x (accesseur)
     * 
     * @return point 
     */
    int getX() const;

     /**
     * @brief Get the Value y (accesseur)
     * @remark const permet de s'assurer que la valeur ne sera pas changer 
     * 
     * @return point 
     */
    int getY() const;

    /**
<<<<<<< HEAD
     * @brief Set the Value object (mutateur)
     *      
     * @param value 
=======
     * @brief Set the new x (mutateur)
     * 
     * @param NewX 
>>>>>>> simon
     */
    void setX(int NewX);

    /**
     * @brief Set the new x (mutateur)
     * 
     * @param NewY 
     */
    void setY(int NewY);

    /**
     * @brief Set the new x (mutateur)
     * 
     * @param NewX
     * @param NewY
     */
    void setXandY(int NewX,int NewY);




    
private:
    // Member variables
    int _x;
    int _y;
};

#endif // CLASS_H