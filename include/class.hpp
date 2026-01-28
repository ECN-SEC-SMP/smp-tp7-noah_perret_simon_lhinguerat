#ifndef CLASS_H
#define CLASS_H

class point {
public:

    /**
     * @brief create a point at origin
     * 
     */
    point();


    /**
     * @brief create a point at fice coordonate
     * 
     */
    point(int x, int y);



    /**
     * @brief create a point at fice coordonate
     * 
     */
    point(const point &);
    
    // Destructor
    ~point();

    // translater
    void translater();
    
    /**
     * @brief Get the Value object (accesseur)
     * 
     * @return point 
     */
    point getValue();

    /**
     * @brief Set the Value object (mutateur)
     * 
     * @param value 
     */
    void setValue(point p);
    
private:
    // Member variables
    int x;
    int y;
};

#endif // CLASS_H