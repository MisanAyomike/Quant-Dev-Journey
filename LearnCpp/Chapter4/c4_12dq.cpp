/* Ask for two floating-point numbers and an operator, then print the result.
   An invalid operator produces no result. */
#include <iostream>

int main()
{
    std::cout<<"Enter 2 two floating point numbers: ";
    double x{}, y{};
    std::cin>>x>>y;
    std::cout<<"Enter one of the following mathematical symbols(+, -, *, or /): ";
    char z;
    std::cin>>z;
    if (z == '+')
    {
        std::cout<< x + y;
    }
    else if (z == '-')
    {
        std::cout<< x - y;
    }
    else if (z == '*')
    {
        std::cout<< x * y;
    }
    else if (z == '/')
    {
        std::cout<< x / y;
    }
    return 0;
}