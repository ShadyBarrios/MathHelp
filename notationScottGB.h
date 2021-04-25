#ifndef NOTATIONSCOTTGB_H
#define NOTATIONSCOTTGB_H
#include "triangleScottGB.h"

class notation{
private:
    double horizontal, vertical;

public:
    notation(){}
    notation(double h, double v){
        horizontal = h;
        vertical = v;
    }

    void notation1(){ // uses <>
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "\n\t<" << horizontal << " , " << vertical << ">\n\n";
        std::cout.flags(originalSettings);
    }

    void notation2(){ // uses [,]   
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "\t[" << horizontal << " , " << vertical << "]\n\n";
        std::cout.flags(originalSettings);
    }

    void notation3(){ // uses i and j
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "\t" << horizontal << "i";
        if(vertical < 0)
            std::cout << " - " << (vertical * -1.0) << "j\n\n";
        else 
            std::cout << " + " << vertical << "j\n\n";

        std::cout.flags(originalSettings);
    }

    void showNotations(){
        notation1(); // <>
        notation3(); // i and j
        notation2(); // [,]
    }
};

#endif