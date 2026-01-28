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
    const int getX();

     /**
     * @brief Get the Value y (accesseur)
     * 
     * @return point 
     */
    const int getY();

    /**
     * @brief Set the Value object (mutateur)
     * 
     * @param value 
     */
    void setValue(point p);
    
private:
    // Member variables
    int _x;
    int _y;
};

#endif // CLASS_H