#include <iostream> //include is a directive that tells the compiler to include the contents
//of the specified file (in this case, the iostream header) in the program before compilation. 
// The iostream header provides facilities for input and output operations, such as reading from standard
// input and writing to standard output.

#define MY_NAME "Alex" // The #define directive is a preprocessor directive that defines a macro. 
//In this case, it defines a macro named MY_NAME with the value "Alex".

int main()
{
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}