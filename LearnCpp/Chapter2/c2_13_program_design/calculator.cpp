#include <iostream>

    // Get input from user
int getUserInput1()
{
    int userInput{};
    std::cout<< "Enter a number: ";
    std::cin >> userInput;
    return userInput;
}

    // Get mathematical operation from user
char getMathematicalOperation()
{
    char operation{};
    std::cout << "Enter a mathematical operation (+, -, *, /): ";
    std::cin >> operation;
    return operation;
}

    // Get second number from user
int getUserInput2()
{
    int userInput{};
    std::cout<< "Enter another number: ";
    std::cin >> userInput;
    return userInput;
}

    // Calculate result
int calculateResult()
{
    int num1{getUserInput1()};
    char operation{getMathematicalOperation()};
    int num2{getUserInput2()};

    switch (operation)
    {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else
            {
                std::cout << "Error: Division by zero is not allowed.\n";
                return 0; // Return 0 or handle the error as needed
            }
        default:
            std::cout << "Error: Invalid operation.\n";
            return 0; // Return 0 or handle the error as needed
    }
    
}

    // Print result
void printResult()
{
    std::cout<< "The result is: " << calculateResult() << '\n';
}

int main()
{
    printResult();
}