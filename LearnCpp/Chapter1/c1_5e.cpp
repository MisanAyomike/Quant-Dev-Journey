#include <iostream>

int main()
{
    int x{};
    std::cout<< x; //prints 0 since x is value-initialized to 0

    int y;
    std::cout<< y; //prints garbage value since y is uninitialized
}