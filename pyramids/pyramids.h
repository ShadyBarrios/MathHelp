#ifndef PYRAMIDS_H
#define PYRAMIDS_H
#include "pyramidsWork.h"
#include "../triangleScottGB.h"
#include <iostream>
#include <iomanip>

class pyramid : public pyramidWork {
private:
    virtual double findBaseArea(){}
protected:
     
public:
    pyramid(){
        baseArea = 0.0;
        slantHeight = 0.0;
        height = 0.0;
        baseLength = 0.0;
        baseWidth = 0.0;
        baseHypotenuse = 0.0;
        volume = 0.0;
        lateral = 0.0;
        total = 0.0;
    }
    void setBaseArea(double ba){baseArea = ba;}
    void setBaseArea(){baseArea = findBaseArea();}
    void setPerimeter(double p){perimeter = p;}
    void setSlantHeight(double sl){slantHeight = sl;}
    void setHeight(double h){height = h;}
    void setBaseLength(double bl){baseLength = bl;}
    void setBaseWidth(double bw){baseWidth = bw;}
    void setBaseHypotenuse(double bh){baseHypotenuse = bh;}
    void setVolume(double v){volume = v;}
    void setLateral(double l){lateral = l;}
    void setTotal(double t){total = t;}
    void setBaseHeight(double bh){baseHeight = bh;}

    double findVolume(){
        double product, result;
        
        volumeFormat();
        volumeStep1();

        product = baseArea * height;

        volumeStep2(product);

        result = product / 3.0;

        volumeStep3(result);

        volume = result;

        return result;
    }

    double findLateral(){ // l = 1/2 * p * sh
        double product, result;

        lateralFormat();
        lateralStep1();

        product = perimeter * slantHeight;

        lateralStep2(product);

        result = product / 2.0;

        lateralStep3(result);

        lateral = result;

        return result;
    }

    double findTotal(){ // total = 1/2 * p * sh + ba
        double product, result;

        totalFormat();
        totalStep1();

        product = (perimeter * slantHeight * 0.5);

        totalStep2(product);

        result = product + baseArea;

        totalStep3(result);

        total = result;

        return result;
    }

    double findHeightVolume(){
        double product, result;

        volumeFormat();
        heightVolumeStep1();

        product = baseArea / 3.0;

        heightVolumeStep2(product);

        result = volume / product;

        heightVolumeStep3(result);

        height = result;

        return result;
    }

    double findBaseAreaVolume(){
        double product, result;

        volumeFormat();
        baseAreaVolumeStep1();

        product = height / 3.0;

        baseAreaVolumeStep2(product);

        result = volume / product;

        baseAreaVolumeStep3(result);

        baseArea = result;

        return result;
    }

    double findPerimeterLateral(){
        double product, result;

        lateralFormat();
        perimeterLateralStep1();

        product = slantHeight / 2.0;

        perimeterLateralStep2(product);

        result = lateral / product;

        perimeterLateralStep3(result);

        perimeter = result;

        return result;
    }

    double findSlantHeightLateral(){
        double product, result;

        lateralFormat();
        slantLateralStep1();

        product = perimeter / 2.0;

        slantLateralStep2(product);

        result = lateral / product;

        slantLateralStep3(result);

        slantHeight = result;

        return result;
    }

    double findBaseAreaTotal(){
        double product, result;

        totalFormat();
        baseAreaTotalStep1();

        product = (perimeter * slantHeight) / 2.0;

        baseAreaTotalStep2(product);

        result = total - product;

        baseAreaTotalStep3(result);

        baseArea = result;

        return result;
    }

    double findPerimeterTotal(){ // total = 1/2 p sh + ba
        double product, difference, result;

        totalFormat();
        perimeterTotalStep1();

        product = slantHeight / 2.0;
        difference = total - baseArea;

        perimeterTotalStep2(product, difference);

        result = difference / product;

        perimeterTotalStep3(result);

        slantHeight = result;
    
        return result;
    }

    double findSlantHeightTotal(){
        double product, difference, result;

        totalFormat();
        slantHeightTotalStep1();

        product = perimeter / 2.0;
        difference = total - baseArea;

        slantHeightTotalStep2(product, difference);

        result = difference / product;

        slantHeightTotalStep3(result);

        slantHeight = result;

        return result;
    }
};

class squarePyramid : public pyramid{
private:
    virtual double findBaseArea(){
        double a;
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "Base area = base length * base width\n";
        std::cout << "Base area = " << baseLength << " * " << baseWidth << std::endl;
        a = baseLength * baseWidth;
        std::cout << "Base area = " << a << std::endl;
        std::cout.flags(originalSettings);
        return a;
    }
protected:
public:
    squarePyramid() : pyramid() {}
};

class trianglePyramid : public pyramid{
private:
    virtual double findBaseArea(){
        double a;
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "Base area = 1/2 * base length * base height (height of base, 2D triangle)\n";
        std::cout << "Base area = 1/2 * " << baseLength << " * " << baseWidth << std::endl;
        a = baseLength * baseWidth * 0.5;
        std::cout << "Base area = " << a << std::endl;
        std::cout.flags(originalSettings);
        return a;
    }

public:
    trianglePyramid() : pyramid() {}
};

#endif
