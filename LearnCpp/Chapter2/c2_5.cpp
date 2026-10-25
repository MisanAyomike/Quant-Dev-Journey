#include <iostream>

int add(int x, int y) // function parameters x and y are local variables
{
    int z{ x + y }; // z is a local variable

    return z;
}// z, y, and x destroyed here

// x is not in scope anywhere in this function
void doSomething()
{
    std::cout << "Hello!\n";
}

int main()
{
    // x can not be used here because it's not in scope yet

    [[maybe_unused]] int x{ 0 }; // x enters scope here and can now be used within this function

    doSomething();

    return 0;
} // x goes out of scope here and can no longer be used