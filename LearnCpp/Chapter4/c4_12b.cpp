#include <iostream>

int main()
{
    char ch{ 97 }; // 97 is ASCII code for 'a'
    // print value of variable ch as an int
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n';

    return 0;
}
/*It’s worth noting that the argument to static_cast evaluates as an expression. 
When we pass in a variable, that variable is evaluated to produce its value, 
and that value is then converted to the new type. 
The variable itself is not affected by casting its value to a new type.*/