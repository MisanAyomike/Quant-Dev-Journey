#include <iostream>

int main()
{
    for (int i{ 10 }; i >= 0; i -= 2) // you can value-initialize i in the loop
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}