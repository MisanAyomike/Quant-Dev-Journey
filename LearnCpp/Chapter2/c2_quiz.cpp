#include <iostream>

/*Write a single-file program (named main.cpp) that reads two separate integers from the user, 
adds them together, and then outputs the answer. The program should use three functions:
*/

//A function named “readNumber” should be used to get (and return) a single integer from the user.

int readNumber()
{
    int x{};
    std::cout << "Enter a number: ";
    std::cin >> x;

    return x;
}

//A function named “writeAnswer” should be used to output the answer. This function should take 
//a single parameter and have no return value.

void writeAnswer(int x, int y)
{
    std::cout<< "The addition of " << x << " and " << y << " is " << x + y; 
}

//A main() function should be used to glue the above functions together.

int main()
{
    int x{readNumber()};
    int y{readNumber()};
    writeAnswer(x, y);

    return 0;
}

