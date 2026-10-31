#include <iostream>

int main()
{
    int outer{0};
    while (outer < 5)
    {
        outer++;
        int inner{5};
        while (inner > outer)
        {
            std::cout<<inner<<' ';
            inner--;
        }
        std::cout<<outer;
        std::cout<<'\n';

    }
    return 0;
}