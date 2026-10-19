#include <iostream>

int doubleValue(int num)
{
    return num * 2;
}
int main()
{
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;
    std::cout << "The double of " << x << " is " << doubleValue(x) << ".\n";
    return 0;
}