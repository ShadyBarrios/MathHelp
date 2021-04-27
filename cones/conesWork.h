#ifndef CONESWORK_H
#define CONESWORK_H
#include <iostream>
#include <iomanip>
#include "..\triangleScottGB.h"

const double pi = 3.141592653589;

class work{
protected:
    double height;
    double slantHeight;
    double surfaceArea;
    double volume;
    double radius;

    void volumeFormat(){
        std::cout << "V = pi * r^2 * (h/3)" << std::endl;
        std::cout << "\tV = volume\n\tR = radius\n\tH = height\n";
    }
    void surfaceAreaLFormat(){
        std::cout << "LSA = pi * r * l" << std::endl;
        std::cout << "\tLSA = lateral surface area (no base)\n\tR = radius\n\tH = height\n";
    }
    void surfaceAreaTFormat(){
        std::cout << "TSA = pi * r * l + (pi * r^2)" << std::endl;
        std::cout << "\tTSA = total surface area (base)\n\tR = radius\n\tH = height\n";
    }

    //////////// find lsa
    void lsaStep1(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "LSA = 3.14 * " << radius << " * " << slantHeight << std::endl;
    }
    void lsaStep2(double product){
        std::cout << "LSA = 3.14 * (" << product << ")" << std::endl;
    }
    void lsaStep3(double result){
        std::cout << "LSA = " << result << std::endl;
        std::cout.flags(originalSettings);
    }
    ///////// find tsa
    void tsaStep1(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "TSA = 3.14 * " << radius << " * " << slantHeight << " + (3.14 * (" << radius << ")^2)" << std::endl;
    }
    void tsaStep2(double product, double product2){
        std::cout << "TSA = 3.14 * " << product << " + " << product2 << std::endl;
    }
    void tsaStep3(double product3, double product2){
        std::cout << "TSA = " << product3 << " + " << product2 << std::endl;
    }
    void tsaStep4(double result){
        std::cout << "TSA = " << result << std::endl;
        std::cout.flags(originalSettings);
    }
    //// find volume
    void volumeStep1(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "V = 3.14 * (" << radius << ")^2 * (" << height << " / 3) " << std::endl;
    }
    void volumeStep2(double square, double quotient){
        std::cout << "V = 3.14 * " << square << " * " << quotient << std::endl;
    }
    void volumeStep3(double result){
        std::cout << "V = " << result << std::endl;
        std::cout.flags(originalSettings);
    }
    // find slant hieght sal
    void slantHeightSalStep1(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << surfaceArea << " = 3.14  * " << radius << " * l" << std::endl;
    }
    void slantHeightSalStep2(double product){
        std::cout << surfaceArea << " = " << product << " * l" << std::endl;
    }
    void slantHeightSalStep3(double result){
        std::cout << result << " = l" << std::endl;
        std::cout.flags(originalSettings);
    }
    // find slant height tal
    void slantHeightSatStep1(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << surfaceArea <<  " = 3.14 * " << radius << " * l + (3.14(" << radius << ")^2)" << std::endl;
    }
    void slantHeightSatStep2(double product, double product2){
        std::cout << surfaceArea << " = " << product << " * l + " << product2 << std::endl;
    }
    void slantHeightSatStep3(double product, double difference){
        std::cout << difference << " = " << product << " * l" << std::endl;
    }
    void slantHeightSatStep4(double result){
        std::cout << result << " = l" << std::endl; 
        std::cout.flags(originalSettings);
    }
    // find height
    void heightStep1(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << volume << " = 3.14 * (" << radius << ")^2 * (h/3)" << std::endl; 
    }
    void heightStep2(double square){
        std::cout << volume << " = 3.14 * " << square << " * (h/3)" << std::endl;
    }
    void heightStep3(double product){
        std::cout << volume << " = " << product << " * (h/3)" << std::endl;
    }
    void heightStep4(double difference){
        std::cout << difference << " = h/3" << std::endl;
    }
    void heightStep5(double result){
        std::cout << result << " = h" << std::endl;
        std::cout.flags(originalSettings);
    }
    // find radius LSA
    void radiusLSAstep1(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << surfaceArea << " = 3.14 * r * " << slantHeight << std::endl;
    }
    void radiusLSAstep2(double product){
        std::cout << surfaceArea << " = " << product << " * r" << std::endl;
    } 
    void radiusLSAstep3(double result){
        std::cout << result << " = r " << std::endl;
        std::cout.flags(originalSettings);    
    }
    // find radius volume
    void radiusVolumeStep1(){
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << volume << " = 3.14 * r^2 * (" << height << "/3)" << std::endl;
    }
    void radiusVolumeStep2(double quotient){
        std::cout << volume << " = 3.14 * r^2 * " << quotient << std::endl;
    }
    void radiusVolumeStep3(double product){
        std::cout << volume << " = " << product << " * r^2" << std::endl;
    }
    void radiusVolumeStep4(double quotient2){
        std::cout << quotient2 << " = r^2" << std::endl; 
    }
    void radiusVolumeStep5(double result){
        std::cout << result << " = r" << std::endl;
        std::cout.flags(originalSettings);
    }
public:
};

#endif