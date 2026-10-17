#include <iostream>

int doubleNumber(int n)
{
    int double_number = n * 2;
    return double_number;
}

int main()
{
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;
    std::cout << "Double that number is: " << doubleNumber(x) << '\n';

    return 0;
}