// made by Scott Gonzalez Barrios
#ifndef PYTHAGOREANSCOTTGB_H
#define PYTHAGOREANSCOTTGB_H
#include <iomanip>
#include <iostream>
#include <cmath>
#include "triangleScottGB.h"

class pythagorean : public triangle{ // inheritance
private: 
    double preRooted; // equivalent to the unknown variable ^2
    double answer; // the answer to the equation

    void format(){ // show default formula
        std::cout << "Work:\n\n";
        std::cout << "Pythagorean Theorem Formula:\n";
        std::cout << "a^2 + b^2 = c^2" << std::endl;
    }

    void sideStep1(){ // substitute in values
        std::cout << "\nStep 1:\n";
        std::cout << "(a)^2 + (" << sideB << ")^2 = (" << sideC << ")^2\n"; 
    } 

    void sideStep2(double difference){  // subtract both sides
        std::cout << "\nStep 2:\n";
        std::cout << "(a)^2 = " << std::fixed << std::showpoint << std::setprecision(2) << difference << std::endl;
    }

    void sideStep3(double result){ // final step, isolate the unknown variable
        std::cout << "\nStep 3:\n";
        std::cout << "a = " << std::fixed << std::showpoint << std::setprecision(2) << result << std::endl;
    }

    void hypoStep1(){ // substitute in values
        std::cout << "Step 1:\n";
        std::cout << std::fixed << std::showpoint << std::setprecision(2) << "(" << sideA << ")^2 + (" << sideB << ")^2 = (c)^2" << std::endl; 
    }

    void hypoStep2(double sum){ // add up A and B
        std::cout << "Step 2:\n";
        std::cout << std::fixed << std::showpoint << std::setprecision(2) << sum << " = (c)^2" << std::endl;
    }

    void hypoStep3(double result){ // final step, isolate the unknown variable
        std::cout << "Step 2:\n";
        std::cout << "c = " << std::fixed << std::showpoint << std::setprecision(2) << result << std::endl;
    }
public:
    double findRegSide(){
        format(); // shows default formula
        sideStep1(); // substitutes in values

        preRooted = pow(sideC, 2.0) - pow(sideB, 2.0);
        sideStep2(preRooted); // combines like terms
        
        answer = sqrt(preRooted);
        sideStep3(answer); // isolates the unknown 

        sideA = answer;

        return sideA;
    }
    double findHypo(){
        format(); // shows default formula
        hypoStep1(); // substitutes in values

        preRooted = pow(sideA, 2.0) + pow(sideB, 2.0);
        hypoStep2(preRooted); // combines like terms

        answer = sqrt(preRooted);
        hypoStep3(answer); // isolates the unknown 

        sideC = answer;

        return sideC;
    }
};

#endif