#include <iostream> // cin and cout
#include <iomanip> // cout manipulation
#include <cmath> // pow and sqrt
#include <cctype> // toupper
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

int main(){
    bool repeat;
    int choice;
    double average, result;
    double angleA, angleB, angleC;
    std::string goBack = "";

    std::cout << "Triangle Trig Aid\nIMPORTANT: USE DEGREES\n";
    std::cout << "By Scott Gonzalez Barrios\n";

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
                    std::cout << "\nGoing back to main menu...\n";
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
            else if(choice == 5){
                std::cout << "Thank you for using my program.\n";
                repeat = false;
            }
        }
        catch(std::string goBack){
            repeat = true;
        }
    } while(repeat);

    return 0;
}

void mainMenu(){
    
    std::cout << "\nChoose your desired mode:\n";
    std::cout << "1) Pythagorean Theorem\n";
    std::cout << "2) Law of Sines\n";
    std::cout << "3) Law of Cosines\n";
    std::cout << "4) Vectors\n";
    std::cout << "5) Quit Program\n";
    std::cout << "Choice (1-5): ";
}

void pythagMenu(){
    std::cout << "Pythagorean Theorem\n";
    std::cout << "1) Find missing side length\n";
    std::cout << "2) Find missing hypotenuse\n";
    std::cout << "3) Go back to main menu\n";
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
    std::cout << "3) Go back to main menu\n";
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
    std::cout << "3) Go back to main menu\n";
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
    std::cout << "4) Go back to main menu\n";
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
        if(choice < 1 || choice > 6){
            std::cout << "That is an invalid option\n";
            std::cout << "Please try again (1 - 6): ";
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