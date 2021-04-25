#ifndef VECTORSSCOTTGB_H
#define VECTORSSCOTTGB_H
#include <iostream>
#include <iomanip>
#include "triangleScottGB.h"
#include "notationScottGB.h"
#include "anglesScottGB.h"
#include <cmath>

void line(){
    std::cout << "-------------------" << std::endl;
}

template<typename T>
class showWork{
public:
    T horizontal, horizontal2, hResult, vertical, vertical2, vResult, mag;

    showWork(){
        horizontal = "X";
        horizontal2 = "X2"; 
        hResult = "X3"; 
        vertical = "Y";
        vertical2 = "Y2"; 
        vResult = "Y3";
        mag = "V";
    }
    showWork(double h, double v){
        horizontal = h;
        vertical = v;
    }
    showWork(double h, double v, double m){
        horizontal = h;
        vertical = v;
        mag = m;
    }
    showWork(double h, double h2, double v, double v2){
        horizontal = h; 
        horizontal2 = h2; 
        hResult = h + h2;
        vertical = v; 
        vertical2 = v2; 
        vResult = v + v2;
    }

    void findResultantWork(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "  <" << horizontal << " , " << vertical << ">" << std::endl;
        std::cout << "+ <" << horizontal2 << " , " << vertical2 << ">" << std::endl;
        line();
        std::cout << "  <" << hResult << " , " << vResult << ">\n" << std::endl;
        std::cout.flags(originalSettings);
    }

    void findMagnitudeWork(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "|| V || = sqrt((" << horizontal << ")^2 + (" << vertical << ")^2)\n" << std::endl;
        std::cout.flags(originalSettings);
    }
};

class vectors{
protected:
    double horizontal;
    double vertical;
    double magnitude;

public:
    vectors(){
        horizontal = 0;
        vertical = 0;
    }
    void set(double h, double v){horizontal = h; vertical = v;}
    double getHoriz(){return horizontal;}
    double getVertical(){return vertical;}

    void findMagnitude(){
        double sum = std::pow(horizontal, 2.0) + std::pow(vertical, 2.0);
        double magnitude = std::sqrt(sum);

        showWork<const char*> temp;
        temp.findMagnitudeWork();

        showWork<double> actual(horizontal, vertical, magnitude);
        actual.findMagnitudeWork();

        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "Magnitude: " << magnitude << std::endl;
        std::cout << std::endl;
        std::cout.flags(originalSettings);
    }

    void findAngles(){
        angles angle(horizontal, vertical);
        angle.showAngles();
    }

};

class resultantVector : public vectors{
private:
    double h1, h2, hR, v1, v2, vR;
public:
    resultantVector(){
        h1 = 0; 
        h2 = 0; 
        hR = 0; 
        v1 = 0;
        v2 = 0; 
        vR = 0;
    }
    void findResultant(double h, double h2, double v, double v2){
        h1 = h; 
        this -> h2 = h2; 
        v1 = v; 
        this -> v2 = v2;
        hR = h1 + h2;
        vR = v1 + v2;

        showWork<const char*> temp;
        temp.findResultantWork();

        showWork<double> actual(h1, h2, v1, v2);
        actual.findResultantWork();

        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "Resultant Vector: " << std::endl;
        notation vector(hR, vR);
        vector.showNotations();

        std::cout.flags(originalSettings);
    }
};

#endif