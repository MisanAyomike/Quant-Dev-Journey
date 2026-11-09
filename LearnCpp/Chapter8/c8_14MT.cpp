#include <iostream>
#include <random> // for std::mt19937 (32 bit) and std::mt19937_64 (64 bit)

int main()
{
    std::mt19937 mt{};
    for (int i{1}; i<=40; i++)
    {
        std::cout<<mt()<<'\t'; //if you forget mt() and use just mt it prints out something 
                               //crazy possibly the whole std::mt19937 list.
        if (i % 5 == 0)
        {
            std::cout<<'\n';
        }

    }
    return 0;
}