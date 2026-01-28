#ifndef CLASS_H
#define CLASS_H

class MyClass {
public:
    // Constructor
    MyClass();
    
    // Destructor
    ~MyClass();
    
    // Member functions
    void doSomething();
    int getValue() const;
    void setValue(int value);
    
private:
    // Member variables
    int m_value;
};

#endif // CLASS_H