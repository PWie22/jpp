
#include "Punkt.hpp"
#include <iostream>

int main() {
    Punkt<int> A(0,-10,0);
    Punkt<unsigned> B(0,10,5);
 
    std::cout << "A(" << A.x << "," << A.y << "," << A.z << ")" << std::endl;
    std::cout << "B(" << B.x << "," << B.y << "," << B.z << ")" << std::endl;
}