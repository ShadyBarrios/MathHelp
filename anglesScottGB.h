#ifndef ANGLESSCOTTGB_H
#define ANGLESSCOTTGB_H
#include "triangleScottGB.h"

class angleLogic{
private:
    int quadrant;
    double initialAngle, finalAngle, setAngle;
    char sign;

public:
    angleLogic(){
        quadrant = 0;
        initialAngle = 0;
        finalAngle = 0;
        setAngle = '0';
    }

    angleLogic(int quad, double initial, double finalA, char sign, std::string direct){
        quadrant = quad; 
        initialAngle = initial;
        finalAngle = finalA;
        this -> sign = sign;

        if(quad == 2 || quad == 3)
            setAngle = 180.00;
        else if(quad == 1)
            setAngle = 0.00;
        else    
            setAngle = 360.00;
    }

    angleLogic(int quad, double initial, double finalA, char sign){
        quadrant = quad;
        initialAngle = initial;
        finalAngle = finalA;
        this -> sign = sign;

        if(quad == 1 || quad == 4)
            setAngle = 90.00;
        else if(quad == 2)
            setAngle = 270.00;
        else    
            setAngle = 180.00;
    }

    void directional(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "Quadrant: " << quadrant << std::endl;
        std::cout << "\tDirectional Angle = " << setAngle << " " << sign <<" " << initialAngle << std::endl;
        std::cout << "\tDirectional Angle = " << finalAngle << std::endl;
    }

    void trueBearing(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "Quadrant: " << quadrant << std::endl;
        std::cout << "\tTrue bearing = " << setAngle << " " << sign << " " << initialAngle << std::endl;
        std::cout << "\tTrue bearing = " << finalAngle << std::endl; 
    }
};

class angles{
private:
    double horizontal, vertical;

public:
    angles(){}
    angles(double h, double v){
        horizontal = h;
        vertical = v;
    }

    double angle(){
        double unitAngle;
        double quotient = vertical / horizontal;

        unitAngle = std::atan(quotient);
        unitAngle = trig::degrees(unitAngle);

        return unitAngle;
    }

    void trueBearing(){ // finds true bearing angle
        double unitAngle = angle();
        double trueB;

        if(horizontal >= 0 && vertical >= 0){ // quadrant 1
            trueB = 90.00 - unitAngle;

            angleLogic daTrabajo(1, unitAngle, trueB, '-');
            daTrabajo.trueBearing();
        }
        else if (horizontal < 0 && vertical >= 0){ // quadrant 2
            trueB = 270.00 - unitAngle;
            unitAngle *= -1;
            angleLogic daTrabajo(2, unitAngle, trueB, '+');
            daTrabajo.trueBearing();
        }
        else if (horizontal < 0 && vertical < 0){ // quadrant 3
            trueB = 180.00 + unitAngle;

            angleLogic daTrabajo(3, unitAngle, trueB, '+');
            daTrabajo.trueBearing();
        }
        else{ // quadrant 4
            trueB = 90.00 - unitAngle;
            unitAngle *= -1;
            angleLogic daTrabajo(4, unitAngle, trueB, '+');
            daTrabajo.trueBearing();
        }

        std::cout << "\tTrue Bearing: " << trueB << " degrees\n";
        std::cout << std::endl;
    }

    void directional(){ // finds directional angle
        double unitAngle = angle();
        double dir;

        if(horizontal >= 0 && vertical >= 0){ // quadrant 1 ++
            dir = unitAngle;

            angleLogic daTrabajo(1, unitAngle, dir, '+', "direct");
            daTrabajo.directional();
        }
        else if (horizontal < 0 && vertical >= 0){ // quadrant 2 -+
            dir = 180.00 + unitAngle; // unitAngle will be negative
            unitAngle *= -1;
            angleLogic daTrabajo(2, unitAngle, dir, '-', "direct");
            daTrabajo.directional();
        }
        else if (horizontal < 0 && vertical < 0){ // quadrant 3 --
            dir = 180.00 + unitAngle; // unitAngle will be positive

            angleLogic daTrabajo(3, unitAngle, dir, '+', "direct");
            daTrabajo.directional();
        }
        else{ // quadrant 4 +-
            dir = 360.00 + unitAngle; // unitAngle will be negative
            unitAngle *= -1;
            angleLogic daTrabajo(4, unitAngle, dir, '-', "direct");
            daTrabajo.directional();
        }

        std::cout << "\tDirectional:  " << dir << " degrees\n";
        std::cout << std::endl;
    }

    void unitCircle(){
        double UCangle = angle();

        if(UCangle < 0)
            std::cout << "\tUnit Circle: " << (UCangle * -1) << " degrees\n";
        else
            std::cout << "\tUnit Circle: " << UCangle << " degrees\n";
        
        std::cout << std::endl;
    }

    void showAngles(){
        trueBearing();
        directional();
        unitCircle();  
    }
};


#endif