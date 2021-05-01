#ifndef PYRAMIDSWORK_H
#define PYRAMIDSWORK_H
#include "../triangleScottGB.h"
#include <iostream>
#include <iomanip>

class pyramidWork{

protected:
    double baseArea, baseHypotenuse, baseHeight, slantHeight, perimeter, height, baseLength, baseWidth, volume, lateral, total;

    // volume
    void volumeFormat(){
        std::cout << "\nVolume = 1/3 * base area * height\n" << std::endl;
        std::cout << std::fixed << std::showpoint << std::setprecision(2); 
    }

    void volumeStep1(){
        std::cout << "Volume = 1/3 * " << baseArea << " * " << height << std::endl << std::endl;
    }
    void volumeStep2(double product){
        std::cout << "Volume = 1/3 * " << product << std::endl << std::endl;
    }
    void volumeStep3(double result){
        std::cout << "Volume = " << result << std::endl << std::endl;
    }

    void heightVolumeStep1(){
        std::cout << volume << " = 1/3 * " << baseArea << " * height\n" << std::endl; 
    }
    void heightVolumeStep2(double product){
        std::cout << volume << " = " << product << " * height" << std::endl << std::endl;
    }
    void heightVolumeStep3(double result){
        std::cout << result << " = height " << std::endl << std::endl;
    }

    void baseAreaVolumeStep1(){
        std::cout << volume << " = 1/3 * base area * " << height << std::endl << std::endl;
    }
    void baseAreaVolumeStep2(double product){
        std::cout << volume << " = " << product << " * base area\n" << std::endl << std::endl;
    }
    void baseAreaVolumeStep3(double result){
        std::cout << result << " = base area" << std::endl << std::endl;
    }
    
    ///////////////////////////////////////////////////////////////
    // lateral
    void lateralFormat(){
        std::cout << "Lateral surface area = 1/2 * perimeter * slant height\n" << std::endl;
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
    }

    void lateralStep1(){
        std::cout << "Lateral SA = 1/2 * " << perimeter << " * " << slantHeight << std::endl << std::endl;
    }
    void lateralStep2(double product){
        std::cout << "Lateral SA = 1/2 * " << product << std::endl << std::endl; 
    }
    void lateralStep3(double result){
        std::cout << "Lateral SA = " << result << std::endl << std::endl;
    }

    void perimeterLateralStep1(){
        std::cout << lateral << " = 1/2 * perimeter * " << slantHeight << std::endl << std::endl;
    }
    void perimeterLateralStep2(double product){
        std::cout << lateral << " = " << product << " * perimeter " << std::endl << std::endl;
    }
    void perimeterLateralStep3(double result){
        std::cout << result << " = perimeter" << std::endl << std::endl;
    }

    void slantLateralStep1(){
        std::cout << lateral << " = 1/2 * " << perimeter << " * slant height\n" << std::endl;
    }
    void slantLateralStep2(double product){
        std::cout << lateral << " = " << product << " * slant height\n" << std::endl;
    }
    void slantLateralStep3(double result){
        std::cout << result << " = slant height\n" << std::endl;
    }
    //////////////////////
    // total
    void totalFormat(){
        std::cout << "Total surface area = 1/2 * perimeter * slant height + base area\n" << std::endl;
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
    }

    void totalStep1(){
        std::cout << "Total SA = (1/2 * " << perimeter << " * " << slantHeight << ") + " << baseArea << std::endl << std::endl;
    }
    void totalStep2(double product){
        std::cout << "Total SA = " << product << " + " << baseArea << std::endl << std::endl;
    }
    void totalStep3(double result){
        std::cout << "Total SA = " << result << std::endl << std::endl;
    }

    void baseAreaTotalStep1(){
        std::cout << total << " = (1/2 * " << perimeter << " * " << slantHeight << ") + base area\n ";
    }
    void baseAreaTotalStep2(double product){
        std::cout << total << " = " << product << " + base area\n" << std::endl;
    }
    void baseAreaTotalStep3(double result){
        std::cout << result << " = base area\n" << std::endl;
    }

    void perimeterTotalStep1(){
        std::cout << total << " = (1/2 * perimeter * " << slantHeight << ") + " << baseArea << std::endl << std::endl;
    }
    void perimeterTotalStep2(double product, double difference){
        std::cout << difference << " = " << product << " * perimeter\n" << std::endl;
    }
    void perimeterTotalStep3(double result){
        std::cout << result << " = perimeter\n" << std::endl; 
    }

    void slantHeightTotalStep1(){
        std::cout << total << " = (1/2 * " << perimeter << " * slant height) + " << baseArea << std::endl << std::endl;
    }
    void slantHeightTotalStep2(double product, double difference){
        std::cout << difference << " = " << product << " * slant height\n" << std::endl;
    }
    void slantHeightTotalStep3(double result){
        std::cout << result << " = slant height\n" << std::endl;
    }
};

#endif
