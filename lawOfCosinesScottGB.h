// made by Scott Gonzalez Barrios
#ifndef LAWOFCOSINESSCOTTGB_H
#define LAWOFCOSINESSCOTTGB_H
#include "triangleScottGB.h"
#include <iostream>
#include <cmath>
#include <iomanip>

class lawOfCosines : public triangle{
private:
    void format(){
        std::cout << "Work:\n\n";
        std::cout << "Law of cosines formula:\n\n";
        std::cout << "\nc^2 = a^2 + b^2 - 2(a)(b)(cos(C))" << std::endl;
        std::cout << std::endl;
    }
    void sideStep1(){
        std::cout << "c^2 = (" << sideA << ")^2 + (" << sideB << ")^2 - 2(" << sideA << ")(" << sideB << ")(cos(";
        std::cout << std::fixed << std::setw(4) << std::showpoint << std::setprecision(1);
        std::cout << angleC << "))" << std::endl;
        std::cout.flags(originalSettings);
        std::cout << std::endl;
    }

    void sideStep2(double sum){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "c^2 = " << sum << " - 2(" << sideA << ")(" << sideB << ")(cos(";
        std::cout.flags(originalSettings);
        std::cout << std::fixed << std::setw(4) << std::showpoint << std::setprecision(1);
        std::cout << angleC << "))" << std::endl;
        std::cout << std::endl;
    }

    void sideStep3(double sum, double product){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "c^2 = " << sum << " - " << product << std::endl;
        std::cout.flags(originalSettings);
        std::cout << std::endl;
    }

    void sideStep4(double difference){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "c^2 = " << difference << std::endl;
        std::cout << std::endl;
    }

    void sideStep5(double squareRoot){
        std::cout << "c = " << squareRoot << std::endl;
        std::cout << std::endl;
    }

    void angleStep1(){ // substitute in values
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "(" << sideC << ")^2 = (" << sideA << ")^2 + (" << sideB << ")^2 - 2(" << sideA <<")("
                    << sideB << ")(cos(A))" << std::endl;
        std::cout << std::endl;
        // no need to reset output format for next part
    }

    void angleStep2(double sum){ // adds a^2 and b^2
        std::cout << "(" << sideC << ")^2 = (" << sum << ") - 2(" << sideA << ")(" << sideB << ")(cos(C))" << std::endl;
        std::cout << std::endl;
        // no need to reset output format
    }

    void angleStep3(double difference, double product){
        std::cout << difference << " = (" << product << ")(cos(C))" << std::endl;
        std::cout << std::endl;
        // no need to reset output format
    }

    void angleStep4(double quotient){
        std::cout << quotient << " = (cos(C))" << std::endl;
        std::cout << std::endl;
        // no need to reset output format
    }

    void angleStep5(double angle){
        std::cout << "C = " << trig::degrees(angle) << " degrees" << std::endl;
        std::cout << std::endl;
    }

public:
    double findSide(){
        double squaredAdded, cosinePart, preRooted, side, result;

        format();
        sideStep1();

        squaredAdded = pow(sideA, 2.0) + pow(sideB, 2.0); // adds a^2 + b^2
        sideStep2(squaredAdded);

        cosinePart = 2 * sideA * sideB * trig::cos(angleC); // multiplies -2(a)(b)(cos(C))
        sideStep3(squaredAdded, cosinePart);

        preRooted = squaredAdded - cosinePart; // subtracts the results from the previous two steps
        sideStep4(preRooted);
        
        result = sqrt(preRooted); // square roots the previous result
        sideStep5(result);

        sideC = result;

        return sideC;
    }
    double findAngle(){
        double squaredAdded, cMinusRest, cosinePart, divided, result;
        double negative2 = -2;

        format();
        angleStep1();

        squaredAdded = pow(sideA, 2.0) + pow(sideB, 2.0); // does a^2 + b^2
        angleStep2(squaredAdded);

        cMinusRest = pow(sideC, 2.0) - squaredAdded; // does c^2 - squareAdded
        cosinePart = negative2 * sideA * sideB;  // does -2ab
        angleStep3(cMinusRest, cosinePart);
        
        divided = cMinusRest / cosinePart;
        angleStep4(divided);

        result = std::acos(divided); // does cos^-1(divided);
        angleStep5(result);

        angleC = result;

        return angleC;
    }
};

#endif