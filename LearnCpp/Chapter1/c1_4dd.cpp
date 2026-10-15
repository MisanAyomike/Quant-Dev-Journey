#include <iostream>

int main()
{
    // [[maybe_unused]] // attribute tells the compiler that a variable may not be used, and to not warn about it.
    [[maybe_unused]] int a; // default-initialization (no initializer)

    // Traditional initiialization forms:
    [[maybe_unused]]int b = 5; // copy-initialization (initial value after equals sign)
    [[maybe_unused]] int c(6); // direct-initialization (initial value inside parentheses)
    
    // Modern initialization form (preferred):
    [[maybe_unused]]int d{7}; // direct-list-initialization (initial value inside braces)
    [[maybe_unused]]int e = {}; // value-initialization (empty braces)
    [[maybe_unused]]int width {5}; // direct-list-initialization of initial value 5 into variable width (preferred) 
    [[maybe_unused]]int height = {6}; // copy-list-initialization of initial value 6 into variable height (rarely used)

    //An integer can only hold non-fractional values.
    //Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold.
    // Such a conversion is a narrowing coversion, since the fractional part of the value will be lost.
    //int w1{4.5}; //compiler error: list-init doesn't allow narrowing conversion
    [[maybe_unused]]int w2 = 4.5; //compiles: w2 copy-init to value 4
    [[maybe_unused]]int w3(4.5); //compiles: w3 direct-init to value 4
    
    //Use direct-list-initialization when you’re actually using the initial value:
    int x { 0 };    // direct-list-initialization with initial value 0
    std::cout << x; // we're using that 0 value here

    /*Use value-initialization when the object’s value is temporary and will be replaced:
    int x1 {};      // value initialization
    std::cin >> x; // we're immediately replacing that value so an explicit 0 would be meaningless
    
    // Traditional initialization forms:
    [[maybe_unused]]int a1, b1; // create variables a and b, but do not initialize them
    [[maybe_unused]]int a1 = 5, b1 = 6;          // copy-initialization
    [[maybe_unused]]int a1, b1 = 5;     // wrong: a1 is not initialized to 5!
    [[maybe_unused]]int c1 ( 7 ), d1 ( 8 );      // direct-initialization
    [[maybe_unused]]int e1 { 9 }, f1 { 10 };     // direct-list-initialization
    */
    [[maybe_unused]]int i {}, j {};            // value-initialization


    return 0;
}
