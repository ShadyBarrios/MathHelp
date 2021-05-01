#include <iostream> // cin and cout
#include <iomanip> // cout manipulation
#include <cmath> // pow and sqrt
#include <cctype> // toupper
#include <vector> // use vectors
#include "cones\cones.h" // imports self-made cone class
#include "pyramids\pyramids.h"
#include "triangleScottGB.h" // imports self-made triangle class (includes a namespace and some functions)
#include "pythagoreanScottGB.h" // imports self-made pythagorean class
#include "lawOfSinesScottGB.h" // imports self-made law of sines class
#include "lawOfCosinesScottGB.h" // imports self-made law of cosines class
#include "vectorsScottGb.h" // imports self-made vectors class (not array vectors, but trig vectors)

struct tests{
    double score;
    std::string name;
    
    void setScore(double amount){
        score = amount;
    }   
    void setName(std::string title){
        name = title;
    }
};
    
/////////// verification methods
void mainMenuVerify(int &); // done - verify input, overloaded by parameter type
void subMenuVerify(int &); // done - verifies is the submenu input is valid (1 or 2)
void vectorMenuVerify(int &); // - verifies input for the vector menu
void positiveVerify(double &); // done - makes sure # is positive
void verify(double &); // done - verify the measurements
void verify(char &); // done - verify restart choice
void oneOrTwoVerify(int &);
void coneMenuVerify(int &); // 
void coneVolumeMenuVerify(int &); // 
void coneSATmenuVerify(int &); //
void coneSALmenuVerify(int &); //
////////// menu methods
void mainMenu(); // done - gives the choice between the 3 equations
void pythagMenu(); // done - gives the user the choice to find regular side or hypotenuse
void pythagInfo(int); // done - user inputs known data
void sineMenu(); // done - gives the user the choice to find side or angle
void sineInfo(int); // done - user inputs known data
void cosineMenu(); // done - gives the user choice to find side or angle
void cosineInfo(int); // done - user inputs known data
void vectorMenu(); // - show possible choices for vector
void regVectorInfo(); // done - gets the info for a regular vector
void resultantVectorInfo(); // done - gets user input for vectors to create resultant vector
void coneMenu(); // vol sat and sal //
void coneVolumeMenu(); // vol h and r // 
void coneVolInfo(); // takes in h and r //
void coneVolhInfo(); // takes in vol and r //
void coneVolrInfo(); // takes in vol and h //
void coneSATmenu(); // sat and sh // 
void coneSALmenu(); // sal sh and r // 
void coneSAinfo(); // takes in r and l //
void coneSAshInfo(); // takes in sa and r //
void coneSALrInfo(); // takes in sal and l //
void pyramidMenu(); // DONE
void pyramidMenu2Verify(int &); // DONE
void pyramidVolumeMenu(); // DONE -  use submenu verify
void pyramidLateralMenu(); // DONE - sq and tri have the same optoins use sub menu verify
void pyramidTotalMenu(); // DONE - create own verify, sq and tri have to same options
void pyramidTotalMenuVerify(int &); // DONE
void pyramidMenu2(); // DONE - must include the type of pyramid in main
void pyramidVolVolumeInfo(int); // DONE - volume for volume info
void pyramidBaVolumeInfo(int); // DONE - base area for volume info
void pyramidHeVolumeInfo(int); //  DONE - height for volume info
void pyramidLaLateralInfo(int); // DONE - lateral for lateral info
void pyramidPeLateralInfo(int); // DONE - perimeter for lateral info
void pyramidShLateralInfo(int); // DONE - slant height for lateral info
void pyramidToTotalInfo(int); // DONE - total for total info
void pyramidPeTotalInfo(int); // DONE - perimeter for total info
void pyramidShTotalInfo(int); // DONE - slant for total info
void pyramidBaTotalInfo(int); // DONE - base area for total info
bool doAgain(); // done - asks user if they want to do again
//////////// logic verification methods
void pythagLogic(double &, double &); // done -makes sure that the hypotenuse isnt smaller than a side length
void sinLogic(double &, double &, double &);  // done - makes sure that there wont be a range error
void cosineLogic(double &, double &, double&); // done - makes sure there wont be a range error

// create global instances of each class
pythagorean pythag; 
lawOfSines sine;
lawOfCosines cosine;
vectors vector1;
vectors vector2;
resultantVector resultant;
cones cone;
squarePyramid sqPyramid;
trianglePyramid triPyramid;

int main(){
    bool repeat;
    int choice;
    double average, result;
    double angleA, angleB, angleC;
    std::string goBack = "";

    std::cout << "Math Aid\nIMPORTANT: USE DEGREES\n";
    std::cout << "By Shady Barrios\n";

    do{
        try{
            mainMenu();
            std::cin >> choice;
            mainMenuVerify(choice);
            std::cout << std::endl;

            std::cout << std::fixed << std::showpoint << std::setprecision(2);
            if(choice == 1){
                pythagMenu();
                std::cin >> choice;
                subMenuVerify(choice);

                if(choice == 3){
                    std::cout << "\nReturning to main menu..." << std::endl;
                    throw goBack;
                }     

                pythagInfo(choice);

                if(choice == 1){
                    result = pythag.findRegSide();
                    std::cout << "Side length: " << result << " units\n\n";
                }
                else if (choice == 2){
                    result = pythag.findHypo();
                    std::cout << "Hypotenuse length: " << result << " units\n\n";
                }
                
                repeat = doAgain();
            }
            else if (choice == 2){
                sineMenu();
                std::cin >> choice;
                subMenuVerify(choice);

                if(choice == 3){
                    std::cout << "\nReturning to main menu..." << std::endl;
                    throw goBack;
                }     

                sineInfo(choice);

                if(choice == 1){
                    result = sine.findSide();
                    std::cout << std::fixed << std::showpoint << std::setprecision(2);
                    std::cout << "Side length: " << result << " units\n\n";
                }
                else if (choice == 2){
                    result = sine.findAngle();
                    std::cout << std::fixed << std::showpoint << std::setprecision(2);
                    std::cout << "Angle measurement: " << trig::degrees(result) << " degrees\n\n";
                }
                
                repeat = doAgain();
            }
            else if (choice == 3){
                cosineMenu();
                std::cin >> choice;
                subMenuVerify(choice);

                if(choice == 3){
                    std::cout << "\nReturning to main menu..." << std::endl;
                    throw goBack;
                }     

                cosineInfo(choice);

                if(choice == 1){
                    result = cosine.findSide();
                    std::cout << "Side length: " << result << " units\n\n";
                }
                else if (choice == 2){
                    result = cosine.findAngle();
                    std::cout << "Angle measurement: " << trig::degrees(result) << " degrees\n\n";
                }
                
                repeat = doAgain();
            }
            else if (choice == 4){
                vectorMenu();
                std::cin >> choice;
                vectorMenuVerify(choice);

                if(choice == 4){
                    std::cout << "\nReturning to main menu...\n";
                    throw goBack;
                }
                
                if(choice == 1){
                    resultantVectorInfo();
                    resultant.findResultant(vector1.getHoriz(), vector2.getHoriz(), vector1.getVertical(), vector2.getVertical());
                    repeat = doAgain();
                }
                else if (choice == 2){
                    regVectorInfo();
                    vector1.findMagnitude();
                    repeat = doAgain();
                }
                else if (choice == 3){
                    regVectorInfo();
                    std::cout << "Angles:\n";
                    vector1.findAngles();
                    repeat = doAgain();
                }
            }
            else if(choice == 5){ // cones
                coneMenu();
                std::cin >> choice;
                coneMenuVerify(choice);
                std::cout << std::endl;

                if(choice == 1){
                    coneVolumeMenu();
                    std::cin >> choice;
                    coneVolumeMenuVerify(choice);
                    std::cout << std::endl;

                    if(choice == 1){
                        coneVolInfo();
                        result = cone.findVolume();
                        std::cout << std::fixed << std::showpoint << std::setprecision(2);
                        std::cout << std::endl;
                        std::cout << "Volume: " << result << std::endl;
                    }
                    else if (choice == 2){
                        coneVolhInfo();
                        result = cone.findHeight();
                        std::cout << std::fixed << std::showpoint << std::setprecision(2);
                        std::cout << std::endl;
                        std::cout << "Height: " << result << std::endl;
                    }
                    else if (choice == 3){
                        coneVolrInfo();
                        result = cone.findRadiusVolume();
                        std::cout << std::fixed << std::showpoint << std::setprecision(2);
                        std::cout << std::endl;
                        std::cout << "Radius: " << result << std::endl;
                    }
                    else if (choice == 4){
                        std::cout << "Returning to main menu...\n";
                        throw goBack;
                    }
                    repeat = doAgain();
                }
                else if(choice == 2){
                    coneSATmenu();
                    std::cin >> choice;
                    coneSATmenuVerify(choice);
                    std::cout << std::endl;

                    if(choice == 1){
                        coneSAinfo();
                        result = cone.findSurfaceAreaT();
                        std::cout << std::fixed << std::showpoint << std::setprecision(2);
                        std::cout << std::endl;
                        std::cout << "Total surface area: " << result << std::endl;
                    }
                    else if(choice == 2){
                        coneSAshInfo();
                        result = cone.findSlantHeightSAT();
                        std::cout << std::fixed << std::showpoint << std::setprecision(2);
                        std::cout << std::endl;
                        std::cout << "Slant height: " << result << std::endl;
                    }
                    else if(choice == 3){
                        std::cout << "Returning to main menu..." << std::endl;
                        throw goBack;
                    }
                    repeat = doAgain();
                }
                else if(choice == 3){
                    coneSALmenu();
                    std::cin >> choice;
                    coneSALmenuVerify(choice);
                    std::cout << std::endl;

                    if(choice == 1){
                        coneSAinfo();
                        result = cone.findSurfaceAreaL();
                        std::cout << std::fixed << std::showpoint << std::setprecision(2);
                        std::cout << std::endl;
                        std::cout << "Lateral surface area: " << result << std::endl;
                    }
                    else if (choice == 2){
                        coneSAshInfo();
                        result = cone.findSlantHeightSAL();
                        std::cout << std::fixed << std::showpoint << std::setprecision(2);
                        std::cout << std::endl;
                        std::cout << "Slant Height: " << result << std::endl;
                    }
                    else if (choice == 3){
                        coneSALrInfo();
                        result = cone.findRadiusSAL();
                        std::cout << std::fixed << std::showpoint << std::setprecision(2);
                        std::cout << std::endl;
                        std::cout << "Radius: " << result << std::endl;
                    }
                    else if (choice == 4){
                        std::cout << "Returning to main menu..." << std::endl;
                        throw goBack;
                    }
                    repeat = doAgain();
                }
                else if(choice == 4){
                    std::cout << "Returning to main menu...\n";
                    throw goBack;
                }
            }
            else if(choice == 6){
                int type;
                pyramidMenu(); // choose tri or square
                std::cin >> type;
                subMenuVerify(type);

                if(type == 1){ // in sq
                    std::cout << "\nSquare Triangles\n";
                    pyramidMenu2(); // choose vol, lat, or tot
                    std::cin >> choice;
                    pyramidMenu2Verify(choice);
                    
                    if(choice == 1){ // chose vol
                        std::cout << "\nVolume\n";
                        pyramidVolumeMenu(); // choose vol, ba, or h
                        std::cin >> choice;
                        subMenuVerify(choice);

                        if(choice == 1){ // chose vol
                            pyramidVolVolumeInfo(type);
                            result = sqPyramid.findVolume();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Volume: " << result << std::endl;
                        }
                        else if (choice == 2){ // chose ba
                            pyramidBaVolumeInfo(type);
                            result = sqPyramid.findBaseAreaVolume();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Base area: " << result << std::endl;
                        }
                        else if (choice == 3){ // chose h
                            pyramidHeVolumeInfo(type);
                            result = sqPyramid.findHeightVolume();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Height: " << result << std::endl;
                        }
                    }
                    else if (choice == 2){ // chose lat
                        std::cout << "\nLateral Surface Area\n";
                        pyramidLateralMenu();
                        std::cin >> choice;
                        subMenuVerify(choice);

                        if(choice == 1){
                            pyramidLaLateralInfo(type);
                            result = sqPyramid.findLateral();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Lateral surface area: " << result << std::endl;
                        }
                        else if (choice == 2){
                            pyramidPeLateralInfo(type);
                            result = sqPyramid.findPerimeterLateral();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Perimeter: " << result << std::endl;
                        }
                        else if (choice == 3){
                            pyramidShLateralInfo(type);
                            result = sqPyramid.findSlantHeightLateral();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Slant height: " << result << std::endl;
                        }
                    }
                    else if (choice == 3){
                        std::cout << "\nTotal Surface Area\n";
                        pyramidTotalMenu();
                        std::cin >> choice;
                        pyramidTotalMenuVerify(choice);

                        if(choice == 1){
                            pyramidToTotalInfo(type);
                            result = sqPyramid.findTotal();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Total surface area: " << result << std::endl;
                        }
                        else if (choice == 2){
                            pyramidPeTotalInfo(type);
                            result = sqPyramid.findPerimeterTotal();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Perimeter: " << result << std::endl;
                        }
                        else if (choice == 3){
                            pyramidShTotalInfo(type);
                            result = sqPyramid.findSlantHeightTotal();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Slant height: " << result << std::endl;
                        }
                        else if (choice == 4){
                            pyramidBaTotalInfo(type);
                            result = sqPyramid.findBaseAreaTotal();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Base area: " << result << std::endl;
                        }
                    }
                    else{
                        std::cout << "Returning to main menu\n";
                        throw goBack;
                    }
                    
                }
                else if (type == 2){ // inside tri
                    std::cout << "\nTriangle Pyramids\n";
                    pyramidMenu2();
                    std::cin >> choice;
                    pyramidMenu2Verify(choice);
                    
                    if(choice == 1){
                        std::cout << "\nVolume\n";
                        pyramidVolumeMenu(); // choose vol, ba, or h
                        std::cin >> choice;
                        subMenuVerify(choice);

                        if(choice == 1){ // chose vol
                            pyramidVolVolumeInfo(type);
                            result = triPyramid.findVolume();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Volume: " << result << std::endl;
                        }
                        else if (choice == 2){ // chose ba
                            pyramidBaVolumeInfo(type);
                            result = triPyramid.findBaseAreaVolume();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Base area: " << result << std::endl;
                        }
                        else if (choice == 3){ // chose h
                            pyramidHeVolumeInfo(type);
                            result = triPyramid.findHeightVolume();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Height: " << result << std::endl;
                        }
                    }
                    else if (choice == 2){
                        std::cout << "\nLateral Surface Area\n";
                        pyramidLateralMenu();
                        std::cin >> choice;
                        subMenuVerify(choice);

                        if(choice == 1){
                            pyramidLaLateralInfo(type);
                            result = triPyramid.findLateral();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Lateral surface area: " << result << std::endl;
                        }
                        else if (choice == 2){
                            pyramidPeLateralInfo(type);
                            result = triPyramid.findPerimeterLateral();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Perimeter: " << result << std::endl;
                        }
                        else if (choice == 3){
                            pyramidShLateralInfo(type);
                            result = triPyramid.findSlantHeightLateral();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Slant height: " << result << std::endl;
                        }
                    }
                    else if (choice == 3){
                        std::cout << "\nTotal Surface Area\n";
                        pyramidTotalMenu();
                        std::cin >> choice;
                        pyramidTotalMenuVerify(choice);

                        if(choice == 1){
                            pyramidToTotalInfo(type);
                            result = triPyramid.findTotal();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Total surface area: " << result << std::endl;
                        }
                        else if (choice == 2){
                            pyramidPeTotalInfo(type);
                            result = triPyramid.findPerimeterTotal();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Perimeter: " << result << std::endl;
                        }
                        else if (choice == 3){
                            pyramidShTotalInfo(type);
                            result = triPyramid.findSlantHeightTotal();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Slant height: " << result << std::endl;
                        }
                        else if (choice == 4){
                            pyramidBaTotalInfo(type);
                            result = triPyramid.findBaseAreaTotal();
                            std::cout << std::fixed << std::showpoint << std::setprecision(2);
                            std::cout << "Base area: " << result << std::endl;
                        }
                    }
                    else{
                        std::cout << "Returning to main menu\n";
                        throw goBack;
                    }
                }
                else{
                    std::cout << "Returning to main menu...\n";
                    throw goBack;
                } 
                repeat = doAgain();
            }
            else if(choice == 7){
                
                repeat = false;
            }
        }
        catch(std::string goBack){
            repeat = true;
        }
    } while(repeat);

    std::cout << "Thank you for using my program.\n";

    return 0;
}

void mainMenu(){
    
    std::cout << "\nChoose your desired mode:\n";
    std::cout << "1) Pythagorean Theorem\n";
    std::cout << "2) Law of Sines\n";
    std::cout << "3) Law of Cosines\n";
    std::cout << "4) Vectors\n";
    std::cout << "5) Cones\n";
    std::cout << "6) Pyramids\n";
    std::cout << "7) Quit Program\n";
    std::cout << "Choice (1 - 7): ";
}

void pythagMenu(){
    std::cout << "Pythagorean Theorem\n";
    std::cout << "1) Find missing side length\n";
    std::cout << "2) Find missing hypotenuse\n";
    std::cout << "3) Return to main menu\n";
    std::cout << "Choice (1 - 3): ";
}

void pythagInfo(int type){
    double sideLength, hypotenuse;
    std::cout << "Input the known information:\n";
    if(type == 1){ // regular side
        std::cout << "Known side length: ";
        std::cin >> sideLength;
        positiveVerify(sideLength);
        
        std::cout << "Hypotenuse: ";
        std::cin >> hypotenuse;
        positiveVerify(hypotenuse);

        pythagLogic(sideLength, hypotenuse);

        pythag.setSideB(sideLength);
        pythag.setSideC(hypotenuse);
    }
    else{
        std::cout << "Known side length 1: ";
        std::cin >> sideLength;
        positiveVerify(sideLength);
        pythag.setSideA(sideLength);

        std::cout << "Known side length 2: ";
        std::cin >> sideLength;
        positiveVerify(sideLength);
        pythag.setSideB(sideLength);
    }
}

void pythagLogic(double &sideLength, double &hypotenuse){
    bool flag;

    do{
        flag = false;
        if(sideLength > hypotenuse){
            std::cout << "\nERROR! Side length cannot be larger than hypotenuse. Try Again.\n\n";

            std::cout << "Known side length: ";
            std::cin >> sideLength;
            positiveVerify(sideLength);
            
            std::cout << "Hypotenuse: ";
            std::cin >> hypotenuse;
            positiveVerify(hypotenuse);

            flag = true;
        }
    }while(flag);
}

void sineMenu(){
    std::cout << "Law of sines\n";
    std::cout << "1) Find missing side length\n";
    std::cout << "2) Find missing angle measurement\n";
    std::cout << "3) Return to main menu\n";
    std::cout << "Choice (1 - 3): ";
}

void sineInfo(int type){
    double angle1, angle2, side1, side2;
    std::cout << "Input the known measurements.\n";
    std::cout << "ANGLES MUST BE IN DEGREES\n";
    if(type == 1){  // find side length
        std::cout << "Unknown side's corresponding angle: ";
        std::cin >> angle1;
        positiveVerify(angle1);
        
        std::cout << "Known side length : ";
        std::cin >> side1;
        positiveVerify(side1);
        
        std::cout << "Known side's corresponding angle: ";
        std::cin >> angle2;
        verify(angle2);
        
        sine.setAngleA(angle1);
        sine.setAngleB(angle2);
        sine.setSideB(side1);
    }
    else{ // find angle
        std::cout << "Unknown angle's corresponding side length: ";
        std::cin >> side1;
        positiveVerify(side1);
        
        std::cout << "Known side length: ";
        std::cin >> side2;
        positiveVerify(side2);
        
        std::cout << "Known side's corresponding angle: ";
        std::cin >> angle2;
        verify(angle2);
        
        sinLogic(side1, side2, angle2);

        sine.setSideA(side1);
        sine.setSideB(side2);
        sine.setAngleB(angle2);
    }
}

void sinLogic(double &side1,double &side2, double &angle){
    double test;
    bool flag;

    do{
        flag = false;

        test = (trig::sin(angle) / side2);
        test = test * side1;

        if(test > 1 || test < -1){
            std::cout << "\nDomain error: \n";
            std::cout << "\tThe numbers inputted create a scenario that cause a domain error.";
            std::cout << "\nPlease try again with new values.\n";
    
            std::cout << "Unknown angle's corresponding side length: ";
            std::cin >> side1;
            positiveVerify(side1);

            std::cout << "Known side length: ";
            std::cin >> side2;
            positiveVerify(side2);
            
            std::cout << "Known side's corresponding angle: ";
            std::cin >> angle;
            verify(angle);

            flag = true;
        }
    }while (flag);
}

void cosineMenu(){

    std::cout << "Law of cosines\n";
    std::cout << "1) Find missing side length\n";
    std::cout << "2) Find missing angle measurement\n";
    std::cout << "3) Return to main menu\n";
    std::cout << "Choice (1 - 3): ";
}

void cosineInfo(int type){
    double angle, side1, side2, side3;
    std::cout << "Input the known measurements\n";
    std::cout << "ANGLES MUST BE IN DEGREES\n";

    if(type == 1){
        std::cout << "Unknown side's corresponding angle: ";
        std::cin >> angle;
        verify(angle);
        
        std::cout << "Known side 1: ";
        std::cin >> side1;
        positiveVerify(side1);
        
        std::cout << "Known side 2: ";
        std::cin >> side2;
        positiveVerify(side2);

        cosine.setAngleC(angle);
        cosine.setSideB(side2);
        cosine.setSideA(side1);
    }
    else{ // find angle
        std::cout << "Unknown angle's corresponding side: ";
        std::cin >> side1;
        positiveVerify(side1);
        
        std::cout << "Known side 1: ";
        std::cin >> side2;
        positiveVerify(side2);
        
        std::cout << "Known side 2: ";
        std::cin >> side3;
        positiveVerify(side3);

        cosineLogic(side1, side2, side3);

        cosine.setSideA(side3);
        cosine.setSideB(side2);
        cosine.setSideC(side1);
    }
}

void cosineLogic(double &side1, double &side2, double &side3){
    bool flag;
    double result1, result2;

    do{
        flag = false;
        result1 = (pow(side3, 2.0)) - (pow(side1, 2.0)) - (pow(side2, 2.0));
        result2 = result1 / (-2 * side3 * side2);

        if(result2 < -1 || result2 > 1){
            std::cout << "\nDomain Error: ";
            std::cout << "\tThe numbers inputted create a scenario that causes a domain error.\n";
            std::cout << "Please try again.\n";

            std::cout << "Unknown angle's corresponding side: ";
            std::cin >> side1;
            positiveVerify(side1);
            
            std::cout << "Known side 1: ";
            std::cin >> side2;
            positiveVerify(side2);
            
            std::cout << "Known side 2: ";
            std::cin >> side3;
            positiveVerify(side3);
        }
    }while (flag);
}

void vectorMenu(){
    std::cout << "Trig Vectors:\n";
    std::cout << "1) Find resultant vector of two vectors\n";
    std::cout << "2) Find magnitude of vector\n";
    std::cout << "3) Find angle of vector\n";
    std::cout << "4) Return to main menu\n";
    std::cout << "Choice (1 - 4): ";
}

void regVectorInfo(){
    std::cout.flags(originalSettings);
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    double v;
    double h;
    std::cout << "\nVector:\n";
    std::cout << "Horizontal Component: ";
    std::cin >> h;
    std::cout << "Vertical Component: ";
    std::cin >> v;

    vector1.set(h, v);

    std::cout << "Vector: <" << vector1.getHoriz() << " , " << vector1.getVertical() << ">\n\n";
}

void resultantVectorInfo(){
    std::cout.flags(originalSettings);
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    double v;
    double h;
    std::cout << "\nVector 1:\n";
    std::cout << "Horizontal Component: ";
    std::cin >> h;
    std::cout << "Vertical Component: ";
    std::cin >> v;

    vector1.set(h, v);

    std::cout << "Vector 1: <" << vector1.getHoriz() << " , " << vector1.getVertical() << ">\n\n";

    std::cout << "Vector 2" << std::endl;
    std::cout << "Horizontal Component: ";
    std::cin >> h;
    std::cout << "Vertical Component: ";
    std::cin >> v;

    vector2.set(h, v);

    std::cout << "Vector 2: <" << vector2.getHoriz() << " , " << vector2.getVertical() << ">\n\n";
}

void mainMenuVerify(int &choice){
    bool flag;
    
    do{
        flag = false;
        if(choice < 1 || choice > 7){
            std::cout << "That is an invalid option\n";
            std::cout << "Please try again (1 - 7): ";
            std::cin >> choice;
            flag = true;
        }
    } while(flag);
}

void subMenuVerify(int &choice){
    bool flag;
    
    do{
        flag = false;
        if(choice < 1 || choice > 3){
            std::cout << "That is an invalid option\n";
            std::cout << "Please try again (1 - 3): ";
            std::cin >> choice;
            flag = true;
        }
    } while(flag);
}

void vectorMenuVerify(int &choice){
    bool flag;
    
    do{
        flag = false;
        if(choice < 1 || choice > 4){
            std::cout << "That is an invalid option\n";
            std::cout << "Please try again (1 - 4): ";
            std::cin >> choice;
            flag = true;
        }
    } while(flag);
}

void verify(double &choice){
    bool flag;
    
    do{
        flag = false;
        if(choice < 1 || choice > 178){
            std::cout << "That is an invalid option\n";
            std::cout << "Please try again (1 - 178): ";
            std::cin >> choice;
            flag = true;
        }
    } while(flag);
}

void verify(char &choice){
    bool flag;

    do{
        flag = false;
        if(toupper(choice) != 'N' && toupper(choice) != 'Y'){
            std::cout << "That is an invalid option\n";
            std::cout << "Please try again (Y or N): ";
            std::cin >> choice;
            flag = true;
        }
    }while(flag);
}

void positiveVerify(double &number){
    bool flag;

    do{
        flag = false;
        if(number < 1){
            std::cout << "That is an invalid input...\n";
            std::cout << "Try again (0<): ";
            std::cin >> number;
            flag = true;
        }
    }while(flag);
}

void coneMenu(){
    std::cout << "Cones:\n";
    std::cout << "1) Volume\n";
    std::cout << "2) Total Surface Area (base)\n";
    std::cout << "3) Lateral Surface Area (no base)\n";
    std::cout << "4) Return to main menu\n";
    std::cout << "Choice (1 - 4): ";
}

void coneMenuVerify(int &choice){
    bool flag;

    do{
        flag = false;
        if(choice < 1 || choice > 4){
            std::cout << "Invalid choice... try again\n";
            std::cout << "Choice (1 - 4): ";
            std::cin >> choice;
            flag = true;
        }
    }while(flag);
}

void coneVolumeMenu(){
    std::cout << "Volume:\n";
    std::cout << "1) Find volume\n";
    std::cout << "2) Find height\n";
    std::cout << "3) Find radius\n";
    std::cout << "4) Return to main menu\n";
    std::cout << "Choice (1 - 4): ";
}

void coneVolumeMenuVerify(int &choice){
    bool flag;

    do{
        flag = false;
        if(choice < 1 || choice > 4){
            std::cout << "Invalid choice... try again\n";
            std::cout << "Choice (1 - 4): ";
            std::cin >> choice;
            flag = true;
        }
    }while(flag);
}

void coneVolInfo(){
    double h, r;
    std::cout << "Input the following information:\n";
    std::cout << "Height: ";
    std::cin >> h;
    positiveVerify(h);
    cone.setHeight(h);

    std::cout << "Radius: ";
    std::cin >> r;
    positiveVerify(r);
    cone.setRadius(r); 
}

void coneVolhInfo(){
    double r, v;
    std::cout << "Input the following information:\n";
    std::cout << "Radius: ";
    std::cin >> r;
    positiveVerify(r);

    std::cout << "Volume: ";
    std::cin >> v;
    positiveVerify(v);

    cone.setRadius(r);
    cone.setVolume(v);
}

void coneVolrInfo(){
    double h, v;
    std::cout << "Input the following information:\n";
    std::cout << "Height: ";
    std::cin >> h;
    positiveVerify(h);

    std::cout << "Volume: ";
    std::cin >> v;
    positiveVerify(v);

    cone.setHeight(h);
    cone.setVolume(v);
}

void coneSAinfo(){
    double r, l;

    std::cout << "Input the following information:\n";
    std::cout << "Slant Height: ";
    std::cin >> l;
    positiveVerify(l);

    std::cout << "Radius: ";
    std::cin >> r;
    positiveVerify(r);

    cone.setRadius(r);
    cone.setSlantHeight(l);
}

void coneSAshInfo(){
    double sa, r;

    std::cout << "Input the following information:\n";
    std::cout << "Surface Area: ";
    std::cin >> sa;
    positiveVerify(sa);

    std::cout << "Radius: ";
    std::cin >> r;
    positiveVerify(r);

    cone.setRadius(r);
    cone.setSurfaceArea(sa);
}

void coneSALrInfo(){
    double sal, l;

    std::cout << "Input the following information:\n";
    std::cout << "Lateral Surface Area: ";
    std::cin >> sal;
    positiveVerify(sal);

    std::cout << "Slant height: ";
    std::cin >> l;
    positiveVerify(l);

    cone.setSlantHeight(l);
    cone.setSurfaceArea(sal);
}

void coneSATmenu(){
    std::cout << "Total Surface Area:\n";
    std::cout << "1) Find total surface area\n";
    std::cout << "2) Find slant height\n";
    std::cout << "3) Return to main menu\n";
    std::cout << "Choice (1 - 3): ";
}

void coneSATmenuVerify(int &choice){
    bool flag;

    do{
        flag = false;
        if(choice < 1 || choice > 3){
            std::cout << "Invalid choice... try again\n";
            std::cout << "Choice (1 - 3): ";
            std::cin >> choice;
            flag = true;
        }
    }while(flag);
}

void coneSALmenu(){
    std::cout << "Lateral Surface Area:\n";
    std::cout << "1) Find lateral surface area\n";
    std::cout << "2) Find slant height\n";
    std::cout << "3) Find radius\n";
    std::cout << "4) Return to main menu\n";
    std::cout << "Choice (1 - 4): ";
}

void coneSALmenuVerify(int &choice){
    bool flag;

    do{
        flag = false;
        if(choice < 1 || choice > 4){
            std::cout << "Invalid choice... try again\n";
            std::cout << "Choice (1 - 4): ";
            std::cin >> choice;
            flag = true;
        }
    }while(flag);
}

void pyramidMenu(){
    std::cout << "Pyramids\n";
    std::cout << "1) Square pyramids\n";
    std::cout << "2) Triangle pyramids\n";
    std::cout << "3) Go back to main menu\n";
    std::cout << "Choice (1 - 3): ";
}

void pyramidMenu2Verify(int &choice){
    bool flag;

    do{
        flag = false;
        if(choice < 1 || choice > 4){
            std::cout << "Invalid choice... try again\n";
            std::cout << "Choice (1 - 4): ";
            std::cin >> choice;
            flag = true;
        }
    }while(flag);
}

void pyramidMenu2(){
    std::cout << "1) Volume\n";
    std::cout << "2) Lateral Surface Area\n";
    std::cout << "3) Total Surface Area\n";
    std::cout << "4) Return to main menu\n";
    std::cout << "Choice (1 - 4): "; // submenu verify takes care of it
}

void pyramidVolumeMenu(){
    std::cout << "1) Find volume\n";
    std::cout << "2) Find base-area\n";
    std::cout << "3) Find height\n";
    std::cout << "Choice (1 - 3): ";
}

void pyramidLateralMenu(){
    std::cout << "1) Find lateral surface area\n";
    std::cout << "2) Find perimeter\n";
    std::cout << "3) Find slant height\n";
    std::cout << "Choice (1 - 3): ";
}

void pyramidTotalMenu(){
    std::cout << "1) Find total surface area\n";
    std::cout << "2) Find perimeter\n";
    std::cout << "3) Find slant height\n";
    std::cout << "4) Find base-area\n";
    std::cout << "Choice (1 - 4): ";
}

void pyramidTotalMenuVerify(int &choice){
    bool flag;

    do{
        flag = false;
        if(choice < 1 || choice > 4){
            std::cout << "Invalid input... try again\n";
            std::cout << "Choice (1 - 4): ";
            std::cin >> choice;
            flag = true;
        }
    }while (flag);
}

void pyramidVolVolumeInfo(int type){
    int choice;
    double b, h, bh, l, w, bhyp;
    std::cout << "Enter the following information:\n";
    std::cout << "Base-area info: ";
    std::cout << "Do you already have the base area or do you need it calculated?\n";
    std::cout << "\t1) Already known\n";
    std::cout << "\t2) Need calculated\n";
    std::cout << "Choice (1 - 2): ";
    std::cin >> choice;
    oneOrTwoVerify(choice);
    
    if(choice == 1){ // they do have it 
        std::cout << "Base area: ";
        std::cin >> b;
        positiveVerify(b);
        if(type == 1)
            sqPyramid.setBaseArea(b);
        else    
            triPyramid.setBaseArea(b);
    }
    else{
        if(type == 1){ // sq
            std::cout << "Base Length: ";
            std::cin >> l;
            positiveVerify(l);
            std::cout << "Base Width: ";
            std::cin >> w;
            positiveVerify(w);
            sqPyramid.setBaseLength(l);
            sqPyramid.setBaseWidth(w);
            sqPyramid.setBaseArea(); 
        }
        else{ // gets info for the tri pyramid
            std::cout << "Base hypotenuse length: ";
            std::cin >> bhyp;
            positiveVerify(bhyp);
            std::cout << "Base height: ";
            std::cin >> bh;
            positiveVerify(bh);
            triPyramid.setBaseLength(bhyp);
            triPyramid.setBaseHeight(bh);
            triPyramid.setBaseArea();
        }
    }
    
    std::cout << "Pyramid height: ";
    std::cin >> h;
    positiveVerify(h);

    if(type == 1){
        sqPyramid.setHeight(h);
    }
    else{   
        triPyramid.setHeight(h);
    }
}

void pyramidBaVolumeInfo(int type){
    double h, v;
    std::cout << "Enter the following information:\n";
    std::cout << "Volume: ";
    std::cin >> v;
    positiveVerify(v);

    std::cout << "Height: ";
    std::cin >> h;
    positiveVerify(h);

    if(type == 1){ // sq
        sqPyramid.setVolume(v); 
        sqPyramid.setHeight(h);
    }
    else{
        triPyramid.setVolume(v);
        sqPyramid.setHeight(h);
    }
}

void pyramidHeVolumeInfo(int type){
    int choice;
    double v, b, bh, l, w, bhyp;
    std::cout << "Enter the following information:\n";
    std::cout << "Base-area info: ";
    std::cout << "Do you already have the base area or do you need it calculated?\n";
    std::cout << "\t1) Already known\n";
    std::cout << "\t2) Need calculated\n";
    std::cout << "Choice (1 - 2): ";
    std::cin >> choice;
    oneOrTwoVerify(choice);
    
    if(choice == 1){ // they do have it 
        std::cout << "Base area: ";
        std::cin >> b;
        positiveVerify(b);
        if(type == 1)
            sqPyramid.setBaseArea(b);
        else    
            triPyramid.setBaseArea(b);
    }
    else{
        if(type == 1){ // sq
            std::cout << "Base Length: ";
            std::cin >> l;
            positiveVerify(l);
            std::cout << "Base Width: ";
            std::cin >> w;
            positiveVerify(w);
            sqPyramid.setBaseLength(l);
            sqPyramid.setBaseWidth(w);
            sqPyramid.setBaseArea(); 
        }
        else{ // gets info for the tri pyramid
            std::cout << "Base hypotenuse length: ";
            std::cin >> bhyp;
            positiveVerify(bhyp);
            std::cout << "Base height: ";
            std::cin >> bh;
            positiveVerify(bh);
            triPyramid.setBaseLength(bhyp);
            triPyramid.setBaseHeight(bh);
            triPyramid.setBaseArea();
        }
    }

    std::cout << "Pyramid volume: ";
    std::cin >> v;
    positiveVerify(v);

    if(type == 1) {
        sqPyramid.setVolume(v);
    }
    else    
        triPyramid.setVolume(v);
}

void oneOrTwoVerify(int &choice){
    bool flag;

    do{
        flag = false;
        if(choice < 1 || choice > 2){
            std::cout << "Invalid input... try again\n";
            std::cout << "Choice (1 - 2): ";
            std::cin >> choice;
            flag = true;
        }
    }while(flag);
}

void pyramidLaLateralInfo(int type){
    double p, sh;

    std::cout << "Input the following information\n";
    std::cout << "Perimeter: ";
    std::cin >> p;
    positiveVerify(p);

    std::cout << "Slant height: ";
    std::cin >> sh;
    positiveVerify(sh);

    if(type == 1){
        sqPyramid.setPerimeter(p);
        sqPyramid.setSlantHeight(sh);
    }
    else{
        triPyramid.setPerimeter(p);
        triPyramid.setSlantHeight(sh);
    }
}

void pyramidPeLateralInfo(int type){
    double l, sh;

    std::cout << "Input the following information\n";
    std::cout << "Lateral surface area: ";
    std::cin >> l;
    positiveVerify(l);

    std::cout << "Slant height: ";
    std::cin >> sh;
    positiveVerify(sh);

    if(type == 1){
        sqPyramid.setLateral(l);
        sqPyramid.setSlantHeight(sh);
    }
    else{
        triPyramid.setLateral(l);
        triPyramid.setSlantHeight(sh);
    }
}

void pyramidShLateralInfo(int type){
    double l, p;

    std::cout << "Input the following information\n";
    std::cout << "Lateral surface area: ";
    std::cin >> l;
    positiveVerify(l);

    std::cout << "Perimeter: ";
    std::cin >> p;
    positiveVerify(p);

    if(type == 1){
        sqPyramid.setLateral(l);
        sqPyramid.setPerimeter(p);
    }
    else{
        triPyramid.setLateral(l);
        triPyramid.setPerimeter(p);
    }
}

void pyramidToTotalInfo(int type){
    int choice;
    double p, sh;

    std::cout << "Input the following information\n";
    std::cout << "Perimeter: ";
    std::cin >> p;
    positiveVerify(p);

    std::cout << "Slant height: ";
    std::cin >> sh;
    positiveVerify(sh);

    double v, b, bh, l, w, bhyp;
    std::cout << "Base-area info: ";
    std::cout << "Do you already have the base area or do you need it calculated?\n";
    std::cout << "\t1) Already known\n";
    std::cout << "\t2) Need calculated\n";
    std::cout << "Choice (1 - 2): ";
    std::cin >> choice;
    oneOrTwoVerify(choice);
    
    if(choice == 1){ // they do have it 
        std::cout << "Base area: ";
        std::cin >> b;
        positiveVerify(b);
        if(type == 1)
            sqPyramid.setBaseArea(b);
        else    
            triPyramid.setBaseArea(b);
    }
    else{
        if(type == 1){ // sq
            std::cout << "Base Length: ";
            std::cin >> l;
            positiveVerify(l);
            std::cout << "Base Width: ";
            std::cin >> w;
            positiveVerify(w);
            sqPyramid.setBaseLength(l);
            sqPyramid.setBaseWidth(w);
            sqPyramid.setBaseArea(); 
        }
        else{ // gets info for the tri pyramid
            std::cout << "Base hypotenuse length: ";
            std::cin >> bhyp;
            positiveVerify(bhyp);
            std::cout << "Base height: ";
            std::cin >> bh;
            positiveVerify(bh);
            triPyramid.setBaseLength(bhyp);
            triPyramid.setBaseHeight(bh);
            triPyramid.setBaseArea();
        }
    }

    if(type == 1){
        sqPyramid.setPerimeter(p);
        sqPyramid.setSlantHeight(sh);
    }
    else{
        triPyramid.setPerimeter(p);
        triPyramid.setSlantHeight(sh);
    }
}

void pyramidPeTotalInfo(int type){
    int choice;
    double t, sh;

    std::cout << "Input the following information\n";
    std::cout << "Total surface area: ";
    std::cin >> t;
    positiveVerify(t);

    std::cout << "Slant height: ";
    std::cin >> sh;
    positiveVerify(sh);

    double v, b, bh, l, w, bhyp;
    std::cout << "Base-area info: ";
    std::cout << "Do you already have the base area or do you need it calculated?\n";
    std::cout << "\t1) Already known\n";
    std::cout << "\t2) Need calculated\n";
    std::cout << "Choice (1 - 2): ";
    std::cin >> choice;
    oneOrTwoVerify(choice);
    
    if(choice == 1){ // they do have it 
        std::cout << "Base area: ";
        std::cin >> b;
        positiveVerify(b);
        if(type == 1)
            sqPyramid.setBaseArea(b);
        else    
            triPyramid.setBaseArea(b);
    }
    else{
        if(type == 1){ // sq
            std::cout << "Base Length: ";
            std::cin >> l;
            positiveVerify(l);
            std::cout << "Base Width: ";
            std::cin >> w;
            positiveVerify(w);
            sqPyramid.setBaseLength(l);
            sqPyramid.setBaseWidth(w);
            sqPyramid.setBaseArea(); 
        }
        else{ // gets info for the tri pyramid
            std::cout << "Base hypotenuse length: ";
            std::cin >> bhyp;
            positiveVerify(bhyp);
            std::cout << "Base height: ";
            std::cin >> bh;
            positiveVerify(bh);
            triPyramid.setBaseLength(bhyp);
            triPyramid.setBaseHeight(bh);
            triPyramid.setBaseArea();
        }
    }

    if(type == 1){
        sqPyramid.setTotal(t);
        sqPyramid.setSlantHeight(sh);
    }
    else{
        triPyramid.setTotal(t);
        triPyramid.setSlantHeight(sh);
    }
}

void pyramidShTotalInfo(int type){
    int choice;
    double t, p;

    std::cout << "Input the following information\n";
    std::cout << "Total surface area: ";
    std::cin >> t;
    positiveVerify(t);

    std::cout << "Perimeter: ";
    std::cin >> p;
    positiveVerify(p);

    double v, b, bh, l, w, bhyp;
    std::cout << "Base-area info: ";
    std::cout << "Do you already have the base area or do you need it calculated?\n";
    std::cout << "\t1) Already known\n";
    std::cout << "\t2) Need calculated\n";
    std::cout << "Choice (1 - 2): ";
    std::cin >> choice;
    oneOrTwoVerify(choice);
    
    if(choice == 1){ // they do have it 
        std::cout << "Base area: ";
        std::cin >> b;
        positiveVerify(b);
        if(type == 1)
            sqPyramid.setBaseArea(b);
        else    
            triPyramid.setBaseArea(b);
    }
    else{
        if(type == 1){ // sq
            std::cout << "Base Length: ";
            std::cin >> l;
            positiveVerify(l);
            std::cout << "Base Width: ";
            std::cin >> w;
            positiveVerify(w);
            sqPyramid.setBaseLength(l);
            sqPyramid.setBaseWidth(w);
            sqPyramid.setBaseArea(); 
        }
        else{ // gets info for the tri pyramid
            std::cout << "Base hypotenuse length: ";
            std::cin >> bhyp;
            positiveVerify(bhyp);
            std::cout << "Base height: ";
            std::cin >> bh;
            positiveVerify(bh);
            triPyramid.setBaseLength(bhyp);
            triPyramid.setBaseHeight(bh);
            triPyramid.setBaseArea();
        }
    }

    if(type == 1){
        sqPyramid.setTotal(t);
        sqPyramid.setPerimeter(p);
    }
    else{
        triPyramid.setTotal(t);
        triPyramid.setPerimeter(p);
    }
}

void pyramidBaTotalInfo(int type){
    double p, sh, t;

    std::cout << "Input the following information\n";
    std::cout << "Perimeter: ";
    std::cin >> p;
    positiveVerify(p);

    std::cout << "Slant height: ";
    std::cin >> sh;
    positiveVerify(sh);

    std::cout << "Total surface area: ";
    std::cin >> t;
    positiveVerify(t);

    if(type == 1){
        sqPyramid.setTotal(t);
        sqPyramid.setSlantHeight(sh);
        sqPyramid.setPerimeter(p);
    }
    else{
        triPyramid.setTotal(t);
        triPyramid.setPerimeter(p);
        triPyramid.setSlantHeight(sh);
    }
}

bool doAgain(){

    char daChar;
    bool repeat;

    std::cout << "Quit program (Y or N)? ";
    std::cin >> daChar;
    verify(daChar); // checks to see if user input is valid

    if(toupper(daChar) == 'Y')
        repeat = false;
    else    
        repeat = true;

    return repeat;
}
