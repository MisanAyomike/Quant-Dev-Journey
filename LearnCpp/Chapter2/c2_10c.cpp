#include <iostream>

int main()
{
    std::cout << "Joe\n";
// #if 0 excludes a block of code from being compiled
#if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    std::cout << "Steve\n";
#endif // until this point

//To temporarily re-enable code that has been wrapped in 
//an #if 0, you can change the #if 0 to #if 1:

    return 0;
}