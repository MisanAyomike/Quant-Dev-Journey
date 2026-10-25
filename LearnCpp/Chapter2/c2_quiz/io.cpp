#include <iostream>
#include "io.h" 

int readNumber()
{
    int x{};
    std::cout << "Enter a number to add: ";
    std::cin >> x;

    return x;
}

void writeAnswer(int x)
{
    std::cout<< "The addition of both numbers is " << x; 
}

