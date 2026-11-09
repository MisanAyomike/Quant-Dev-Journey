#include <iostream>

int six()
{
    return 6;
}

int pass(const int x) // x is a runtime constant
{
    return x;
}

int main()
{
    // The following are non-constants:
    [[maybe_unused]] int a { 7 };

    // The following are compile-time constants:
    [[maybe_unused]] const int b { 8 };
    [[maybe_unused]] const double c { 1.2 };
    [[maybe_unused]] const int d { b };       // b is a compile-time constant

    // The following are runtime constants:
    [[maybe_unused]] const int e { a };       // a is non-const
    [[maybe_unused]] const int f { e };       // e is a runtime constant
    [[maybe_unused]] const int g { six() };  // return value isn't known until runtime
    [[maybe_unused]] const int h { pass(5) }; // return value isn't known until runtime


    std::cout<< a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n' << f << '\n' << g << '\n' << h << '\n';
    return 0;
}