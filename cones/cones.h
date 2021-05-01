#ifndef CONES_H
#define CONES_H
#include <iostream>
#include <cmath>
#include <iomanip>
#include "conesWork.h"

// SA = pi*r*s + pi*r^2
// s = slant height

// V = pi*r^2 * h/3
// h = height
class cones : private work{
private:
    // variables inherited from work
public:
    cones(){
        height = 0.0;
        slantHeight = 0.0;
        surfaceArea = 0.0;
        volume = 0.0;
        radius = 0.0;
    }
    void setHeight(double h){height = h;}
    void setSlantHeight(double sh){slantHeight = sh;}
    void setSurfaceArea(double sa){surfaceArea = sa;}
    void setVolume(double v){volume = v;}
    void setRadius(double r){radius = r;}

    double findVolume(){
        double result;

        volumeFormat();
        volumeStep1();

        double square;
        square = std::pow(radius, 2.0);
        double quotient = height / 3.0;

        volumeStep2(square, quotient);

        result = pi * square * quotient;

        volumeStep3(result);

        volume = result;

        return volume;
    }
    double findHeight(){
        double result, square, product, difference;

        volumeFormat();
        heightStep1();

        square = std::pow(radius, 2.0);

        heightStep2(square);

        product = pi * square;

        heightStep3(product);

        difference = volume / product;

        heightStep4(difference);

        result = difference * 3.0;

        heightStep5(result);

        height = result;

        return result;
    }
    double findSlantHeightSAL(){
        double product, result;

        surfaceAreaLFormat();
        slantHeightSalStep1();

        product = pi * radius;

        slantHeightSalStep2(product);

        result = surfaceArea / product;

        slantHeightSalStep3(result);

        slantHeight = result;

        return slantHeight;
    }
    double findSlantHeightSAT(){
        double product, product2, difference, result;

        surfaceAreaTFormat();
        slantHeightSatStep1();

        product = radius * pi;
        product2 = pi * std::pow(radius, 2.0);

        slantHeightSatStep2(product, product2);

        difference = surfaceArea - product2;

        slantHeightSatStep3(product, difference);

        result = difference / product;

        slantHeightSatStep4(result);

        slantHeight = result;

        return slantHeight;
    }
    double findRadiusVolume(){
        double quotient, quotient2, product, result;

        volumeFormat();
        radiusVolumeStep1();

        quotient = height / 3.0;

        radiusVolumeStep2(quotient);

        product = quotient * pi;

        radiusVolumeStep3(product);

        quotient2 = volume / product;

        radiusVolumeStep4(quotient2);

        result = std::sqrt(quotient2);

        radiusVolumeStep5(result);

        radius = result;

        return radius;
    }
    double findRadiusSAL(){
        double product, result;

        surfaceAreaLFormat();
        radiusLSAstep1();

        product = slantHeight * pi;

        radiusLSAstep2(product);

        result = surfaceArea / product;

        radiusLSAstep3(result);

        radius = result;

        return radius;
    }
    double findSurfaceAreaL(){
        double square, product, result;

        surfaceAreaLFormat();
        lsaStep1();

        product = slantHeight * square;

        lsaStep2(product);

        result = product * pi;

        lsaStep3(result);

        surfaceArea = result;

        return surfaceArea;
    }
    double findSurfaceAreaT(){
        double product, product2, product3, result;

        surfaceAreaTFormat();
        tsaStep1();

        product2 = pi * std::pow(radius, 2.0);
        product = radius * slantHeight;

        tsaStep2(product, product2);

        product3 = product * pi;

        tsaStep3(product3, product2);

        result = product3 + product2;

        tsaStep4(result);

        surfaceArea = result;

        return surfaceArea;
    }
};

#endif
