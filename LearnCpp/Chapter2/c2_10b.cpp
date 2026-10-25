#include <iostream>

#define PRINT_JOE

//The #ifdef preprocessor directive allows the preprocessor to check whether an identifier has 
// been previously defined via #define. If so, the code between the #ifdef and matching #endif is compiled.
// If not, the code is ignored.
// #ifndef is the opposite of #ifdef, which allows you to check if an identifier has NOT been #defined yet.

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

    return 0;
}