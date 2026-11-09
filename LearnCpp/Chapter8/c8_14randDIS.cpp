#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution

int main()
{
    std::mt19937 mt{};
    std::uniform_int_distribution die6{1, 6};

    for (int i{1}; i <= 40; i++)
    {
        std::cout<<die6(mt)<<'\t';
        if (i % 10 == 0)
        {
            std::cout<<'\n';
        }
    }
    return 0;
}