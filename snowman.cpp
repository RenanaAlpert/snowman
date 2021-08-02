#include "snowman.hpp"
#include <array>

/**************************************************************
 * Create a hat to the snowman:                    
 * 1.1 _===_                                        
 *       ___                                      
 * 1.2  .....
 *       _  
 * 1.3  /_\ 
 *      ___ 
 * 1.4 (_*_)
 ***************************************************************/
string createHat(const int &code)
{
    string hat;

    switch (code)
    {
    case 1:
        hat = " _===_ \n";
        break;
    
    case 2:
        hat = "  ___  \n ..... \n";
        break;
    
    case 3:
        hat = "   _   \n  /_\\  \n";
        break;

    case 4:
        hat = "  ___  \n (_*_) \n";
        break;    

    default:
        throw std::invalid_argument{"wromg digit! - please enter digit between 1-4"};
        break;
    }
    return hat;
}

/**************************************************************
 * Create a nose/mouth to the snowman:                      
 * 2.1 ,                                       
 * 2.2 .
 * 2.3 _
 * 2.4 None
 ***************************************************************/
string createNose(const int &code)
{
    string nose;

    switch (code)
    {
    case 1:
        nose = ",";
        break;
    
    case 2:
        nose = ".";
        break;
    
    case 3:
        nose = "_";
        break;

    case 4:
        nose = " ";
        break;    

    default:
        throw std::invalid_argument{"wromg digit! - please enter digit between 1-4"};
        break;
    }
    return nose;
}

/**************************************************************
 * Create a left eye to the snowman:                     
 * 3.1 .                                       
 * 3.2 o
 * 3.3 O
 * 3.4 -
 ***************************************************************/
string createLeftEye(const int &code)
{
    string leftEye;

    switch (code)
    {
    case 1:
        leftEye = ".";
        break;
    
    case 2:
        leftEye = "o";
        break;
    
    case 3:
        leftEye = "O";
        break;

    case 4:
        leftEye = "-";
        break;    

    default:
        throw std::invalid_argument{"wromg digit! - please enter digit between 1-4"};
        break;
    }
    return leftEye;
}

/**************************************************************
 * Create a right eye to the snowman:                     
 * 4.1 .                                       
 * 4.2 o
 * 4.3 O
 * 4.4 -
 ***************************************************************/
string createRightEye(const int &code)
{
    string rightEye;

    switch (code)
    {
    case 1:
        rightEye = ".";
        break;
    
    case 2:
        rightEye = "o";
        break;
    
    case 3:
        rightEye = "O";
        break;

    case 4:
        rightEye = "-";
        break;    

    default:
        throw std::invalid_argument{"wromg digit! - please enter digit between 1-4"};
        break;
    }
    return rightEye;
}

/**************************************************************
 * Create a left arm to the snowman:                     
 * 5.1 \..n<                                       
 * 5.2 \\n
 * 5.3 \..n/
 * 5.4 None
 ***************************************************************/
string createLeftArm(const int &code)
{
    string leftArm;

    switch (code)
    {
    case 1:
        leftArm = "<";
        break;
    
    case 2:
        leftArm = "\\";
        break;
    
    case 3:
        leftArm = "/";
        break;

    case 4:
        leftArm = " ";
        break;    

    default:
        throw std::invalid_argument{"wromg digit! - please enter digit between 1-4"};
        break;
    }
    return leftArm;
}

/**************************************************************
 * Create a right arm to the snowman:                     
 * 6.1 \ n>                                      
 * 6.2 /\ n
 * 6.3 \ n\
 * 6.4 None
 ***************************************************************/
string createRightArm(const int &code)
{
    string rightArm;

    switch (code)
    {
    case 1:
        rightArm = ">";
        break;
    
    case 2:
        rightArm = "/";
        break;
    
    case 3:
        rightArm = "\\";
        break;

    case 4:
        rightArm = " ";
        break;    

    default:
        throw std::invalid_argument{"wromg digit! - please enter digit between 1-4"};
        break;
    }
    return rightArm;
}

/**************************************************************
 * Create a torso to the snowman:                     
 * 7.1  :                                      
 * 7.2 ] [
 * 7.3 > <
 * 7.4 None
 ***************************************************************/
string createTorso(const int &code)
{
    string torso;

    switch (code)
    {
    case 1:
        torso = " : ";
        break;
    
    case 2:
        torso = "] [";
        break;
    
    case 3:
        torso = "> <";
        break;

    case 4:
        torso = "   ";
        break;    

    default:
        throw std::invalid_argument{"wromg digit! - please enter digit between 1-4"};
        break;
    }
    return torso;
}


/**************************************************************
 * Create a base to the snowman:                     
 * 8.1  :                                     
 * 8.2 " "
 * 8.3 ___
 * 8.4 None
 ***************************************************************/
string createBase(const int &code)
{
    string base;

    switch (code)
    {
    case 1:
        base = " : ";
        break;
    
    case 2:
        base = "\" \"";
        break;
    
    case 3:
        base = "___";
        break;

    case 4:
        base = "   ";
        break;    

    default:
        throw std::invalid_argument{"wromg digit! - please enter digit between 1-4"};
        break;
    }
    return base;
}

/**************************************************************
 * Create the snowman.
 ***************************************************************/

const int NUM_OF_PARTS = 8;
const int D = 10;

string ariel::snowman(int code)
{
    if (code < 0)
    {
        throw std::invalid_argument{"negative input!- please enter positive number"};
    }

    array<int, NUM_OF_PARTS> body = {0};
    for (int i = NUM_OF_PARTS - 1; i >= 0; i--)
    {
        if (code == 0)
        {
            throw std::invalid_argument{"input too short!- please enter 8 digit"};
        }
        body.at(i) = code % D;
        code /= D;
    }

    if (code != 0)
    {
        throw std::invalid_argument{"input too long!- please enter 8 digit"};
    }

    string hat = createHat(body.at(HAT));        // hat
    string nose = createNose(body.at(NOSE));      // nose/mouth
    string L_eye = createLeftEye(body.at(LE));  // left eye
    string R_eye = createRightEye(body.at(RE)); // right eye
    string L_arm = createLeftArm(body.at(LA));  // left arm
    string R_arm = createRightArm(body.at(RA)); // right arm
    string torso = createTorso(body.at(TORSO));    // torso
    string base = createBase(body.at(BASE));      // base

    string lTop = (body.at(LA) == 2) ? L_arm : " ";
    string rTop = (body.at(RA) == 2) ? R_arm : " ";
    string top = lTop + "(" + L_eye + nose + R_eye + ")" + rTop + "\n";

    string lMiddle = (lTop == " ") ? L_arm : " ";
    string rMiddle = (rTop == " ") ? R_arm : " ";
    string middle = lMiddle + "(" + torso + ")" + rMiddle + "\n";

    string bottom = " (" + base + ") \n";

    string snowmanBody = hat + top + middle + bottom;
    return snowmanBody;
}