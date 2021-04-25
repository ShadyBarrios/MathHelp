// made by Scott Gonzalez Barrios
#ifndef LAWOFSINESSCOTTGB_H
#define LAWOFSINESSCOTTGB_H
#include "triangleScottGB.h"
#include <iostream>
#include <iomanip>
#include <cmath>

class lawOfSines : public triangle{ // inheritance
private:
    void format(){
        std::cout << "Work:\n\n";
        std::cout << "Law of sines formula:\n\n";
        std::cout << "   sin(A)        sin(B)\n"; // top row
        middle(); // middle row "---- = ----"
        std::cout << "     a             b\n" << std::endl; // bottom row
    }

    void sideStep1(){ // substitutes in values
        std::cout << std::setw(4) << std::showpoint << std::setprecision(1); // formatting for the values inside sin()
        std::cout << " sin(" << angleA << ")     sin(" << angleB << ")\n"; // top row
        middle(); // middle row
        std::cout.flags(originalSettings); // resets formatting
        std::cout << std::fixed; // makes program show every digit of the sides
        std::cout << "     a            " << sideB << std::endl; // bottom row
        std::cout << std::endl; // creates empty line
    }

    void sideStep2(double quotient){ // divides top and bottom on right side of the equation
        std::cout << std::setw(4) << std::showpoint << std::setprecision(1); // formatting for the sin()
        std::cout << " sin(" << angleA << ")" << std::endl; // top row
        halfMiddle(); // middle row, "---- = "
        std::cout.flags(originalSettings); // resets formatting
        std::cout << quotient << std::endl; // shows result, "---- = *answer*"
        std::cout << "     a" << std::endl; // bottom row
        std::cout << std::endl; // creates empty line

        sideStep3(quotient); // calls next step here instead of during the actual procedure
    } 

    // UPDATE STEP 3
    void sideStep3(double quotient){ // shows the right side being divided by the unknown's sin()
        std::cout << std::fixed << std::showpoint << std::setprecision(2); // formats the output
        std::cout << "        " << quotient << std::endl;
        std::cout << "a"; // the variable is isolated on the left
        halfMiddle2(); // should print "= --------"
        std::cout.flags(originalSettings); // resets the output formatting 
        std::cout << std::fixed << std::setw(4) << std::showpoint << std::setprecision(1); // new formatting
        std::cout << "     sin(" << angleA << ")" << std::endl; // outputs the sin and its angle
        std::cout << std::endl; // creates a new line
    }

    void sideStep4(double result){
        std::cout << std::fixed << std::showpoint << std::setprecision(2); // formatting for the output
        std::cout << "a = " << result << std::endl; // isolates the unknown
        std::cout << std::endl; // creates new lines
        std::cout.flags(originalSettings); // resets formatting
    }

    void angleStep1(){ // substitute values
        std::cout << std::setw(4) << std::showpoint << std::setprecision(1); // output formatting
        std::cout << "   sin(A)      sin(" << angleB << ")" << std::endl; //substitute in angle for 'B'
        middle(); // should print "--- = ---"
        std::cout.flags(originalSettings); // resets output formatting
        std::cout << std::fixed << std::showpoint << std::setprecision(2); // new formatting
        std::cout << "   " << sideA << "          " << sideB << std::endl; // substitute in side lengths
        std::cout.flags(originalSettings); // resets formatting
        std::cout << std::endl; // new line
    }

    void angleStep2(double quotient){ //divide right side
        std::cout << std::fixed << std::showpoint << std::setprecision(2); // output formatting
        std::cout << "   sin(a) " << std::endl; // only puts sin for A, not for B
        halfMiddle(); // should print "--- = "
        std::cout << quotient << std::endl; // print the result from sinB / b
        std::cout << "   " << sideA << std::endl; // prints side length a
        std::cout << std::endl; // new line

        angleStep3(quotient); // calls step 3
    }

    void angleStep3(double quotient){ // multiplies the result from the last step time side a
        std::cout << "sin(A) = " << quotient << " x " << sideA << std::endl; 
        std::cout << std::endl;
    }

    void angleStep4(double product){
        std::cout << "sin(A) = " << product << std::endl;
        std::cout << std::endl;
    }

    void angleStep5(double result){
        std::cout << "A = " << result << std::endl;
        std::cout << std::endl;
    }
public:
    double findSide(){
        double result1, result2;

        format();
        sideStep1();

        result1 = trig::sin(angleB) / sideB;
        sideStep2(result1); // sideStep3 will be called within step 2

        result2 = trig::sin(angleA) / result1;
        sideStep4(result2);

        sideA = result2;

        return sideA;
    }
    double findAngle(){
        double result1, result2, result3;

        format();
        angleStep1();

        result1 = trig::sin(angleB) / sideB;
        angleStep2(result1); // calls step 3 within function

        result2 = result1 * sideA;
        angleStep4(result2);

        result3 = std::asin(result2);
        angleStep5(result3);

        angleA = result3;
        return angleA;
    }
};

#endif