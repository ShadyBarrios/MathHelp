// made by Scott Gonzalez Barrios
#ifndef TRIANGLESCOTTGB_H
#define TRIANGLESCOTTGB_H
#include <iostream>
#include <iomanip>
#include <cmath>

namespace trig{ // trig:: will allow user to input degrees and not require radians, overrides std::
    // pi is long for higher accuracy
    double sin(double angle){ // returns sin of an angle inputted in degrees
        return std::sin((angle * 3.14159265359) / 180.0);
    }
    double cos(double angle){ // returns the cos of an angle inputted in degrees
        return std::cos((angle * 3.14159265359) / 180.0);
    }
    double degrees(double angle){ // converts radians to degrees
        return ((angle * 180.0) / 3.14159265359);
    }
};

// save cout original formatting
std::ios::fmtflags originalSettings = std::cout.flags();

void middle(){ // so that i dont have to keep typing this out
    std::cout << "----------- = -----------" << std::endl; 
}

void halfMiddle(){ // same as middle()
    std::cout << "----------- = ";
}

void halfMiddle2(){ // opposite of halfMiddle2()
    std::cout << " = -----------" << std::endl;
}

// pythag
class triangle{ // to be used as parent class
protected: // can be accessed by classes that inherit this one
    double sideA;
    double sideB;
    double sideC;
    double angleA;
    double angleB;
    double angleC;

public: 
    // accessor functions
    // no need to create "get" functions as the inherited classes already have access to them
    // sides
    void setSideA(double A){
        sideA = A;
    }
    void setSideB(double B){
        sideB = B;
    }
    void setSideC(double C){
        sideC = C;
    }
    // angles
    void setAngleA(double A){
        angleA = A;
    }
    void setAngleB(double B){
        angleB = B;
    }
    void setAngleC(double C){
        angleC = C;
    }
};

#endif