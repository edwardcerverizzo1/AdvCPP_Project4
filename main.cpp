
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
// #include "createMap.h"
#include <list>
#include "polyclass.h"



int main(){

    std::cout<< "Started" << std::endl;

    // Read input
    std::ifstream stream;
    stream.open("input.txt");
    int coff, exp;

    std::string poly1;
    std::string poly2;

    std::cout<< "Reading input" << std::endl;
    std::getline(stream, poly1);
    std::getline(stream, poly2);


    // debug
    std::cout<< poly1 << std::endl;
    std::cout<< poly2 << std::endl;

    // std::map<int, int> m1;
    // std::map<int, int> m2;

    // m1 = createMap(poly1);
    // m2 = createMap(poly2);

    poly p1 (poly1);
    poly p2 (poly2);

    std::cout<< "p1's map: \n";
    p1.displayMap();
    std::cout<< "p2's map: \n";
    p2.displayMap();
    


    poly p3 = p1.operator+(p2);
    std::cout<< "p3's map: \n";
    p3.displayMap();

    p3 = p1.operator-(p2);
    std::cout<< "p3's map: \n";
    p3.displayMap();

    p3 = p1.operator*(p2);
    std::cout<< "p3's map: \n";
    p3.displayMap();

    poly p4 = p1.operator*(p2);
    std::cout<< "p4's map: \n";
    p4.displayMap();

    std::cout << p4; 

    std::ofstream of;
    of.open("output.txt");

    of << "operator+ \n";
    of << p1.operator+(p1) <<std::endl;

    of << "operator-\n";
    of << p1.operator-(p1) <<std::endl;

    of << "operator*\n";
    of << p1.operator*(p1) <<std::endl;


    return 0;
}