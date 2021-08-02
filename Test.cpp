#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/*****************************************************************
 * Bad inputs
 *****************************************************************/

TEST_CASE("Bad input- type: boolean"){
    CHECK_THROWS(snowman(1243<241));
    CHECK_THROWS(snowman(13452<49));
    CHECK_THROWS(snowman(1243>241));
    CHECK_THROWS(snowman(13452>49));
    CHECK_THROWS(snowman(true));
    CHECK_THROWS(snowman(false));
}

TEST_CASE("Bad input- type: random symbol"){
    CHECK_THROWS(snowman(1243'241));
    CHECK_THROWS(snowman(13452'49));
    CHECK_THROWS(snowman(1243^241));
    CHECK_THROWS(snowman(13452^49));
}

TEST_CASE("Bad input- negative numbers"){
    CHECK_THROWS(snowman(-21122113));
    CHECK_THROWS(snowman(-81122613));
    CHECK_THROWS(snowman(-1122113));
    CHECK_THROWS(snowman(-6541432));
}

TEST_CASE("Bad input- too short"){
    CHECK_THROWS(snowman(4));
    CHECK_THROWS(snowman(5));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(62));
    CHECK_THROWS(snowman(122));
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(1211));
    CHECK_THROWS(snowman(7354));
    CHECK_THROWS(snowman(12113));
    CHECK_THROWS(snowman(55161));
    CHECK_THROWS(snowman(443321));
    CHECK_THROWS(snowman(256318));
    CHECK_THROWS(snowman(1333244));
    CHECK_THROWS(snowman(6655887));
}

TEST_CASE("Bad input- digit bigger then 4"){
    CHECK_THROWS(snowman(81122113));
    CHECK_THROWS(snowman(45222341));
    CHECK_THROWS(snowman(11622344));
    CHECK_THROWS(snowman(11262333));
    CHECK_THROWS(snowman(11229333));
    CHECK_THROWS(snowman(11223633));
    CHECK_THROWS(snowman(11223353));
    CHECK_THROWS(snowman(11133349));
}

TEST_CASE("Bad input- digit 0"){
    CHECK_THROWS(snowman(11133340));
    CHECK_THROWS(snowman(11030349));
    CHECK_THROWS(snowman(00));
}

TEST_CASE("Bad input- too long"){
    CHECK_THROWS(snowman(124312241));
    CHECK_THROWS(snowman(142365131));
    CHECK_THROWS(snowman(1324214321));
    CHECK_THROWS(snowman(1500012354));
}


/*****************************************************************
 * Parts of the body
 *****************************************************************/

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

/*
    1. hat:
        1.1 _===_
              ___ 
        1.2  .....
              _  
        1.3  /_\   
             ___ 
        1.4 (_*_)
*/
TEST_CASE("good code - hats"){
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces(" ___ \n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31114411)) == nospaces(" _ \n/_\\\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces(" ___ \n(_*_)\n(.,.)\n( : )\n( : )"));
}

/*
    2. nose/mouth:
        2.1 ,
        2.2 .
        2.3 _
        2.4 None
*/
TEST_CASE("good code - nose/mouth"){
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
}

/*
    3. left eye:
        3.1 .
        3.2 o
        3.3 O
        3.4 -
*/
TEST_CASE("good code - left eye"){
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));
}

/*
    4. right eye:
        3.1 .
        3.2 o
        3.3 O
        3.4 -
*/
TEST_CASE("good code - right eye"){
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
}

/*
    5. left arm:
        5.1 \n<
        5.2 \\n
        5.3 \n/
        5.4 None
*/
TEST_CASE("good code - left arm"){
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
    CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

/*
    6. right arm:
        6.1 \n>
        6.2 /\n
        6.3 \n\
        6.4 None
*/
TEST_CASE("good code - right arm"){
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

/*
    7. torso:
        7.1  :
        7.2 ] [
        7.3 > <
        7.4 None
*/
TEST_CASE("good code - torso"){
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )"));
    CHECK(nospaces(snowman(11114431)) == nospaces("_===_\n(.,.)\n(> <)\n( : )"));
    CHECK(nospaces(snowman(11114441)) == nospaces("_===_\n(.,.)\n(   )\n( : )"));
}

/*
    8. base:
        8.1  :
        8.2 " "
        8.3 ___
        8.4 None
*/
TEST_CASE("good code - base"){
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114412)) == nospaces("_===_\n(.,.)\n( : )\n(\" \")"));
    CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)"));
    CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n(   )"));
}
