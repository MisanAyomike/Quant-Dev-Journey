#include <iostream>
int main()
{
    std::cout << "Enter two numbers: ";
    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    std::cout << "You entered: " << x << " and " << y << '\n';
    return 0;
}

/* Run #1: When std::cin >> x; is encountered, the program will wait for input. Enter the value 4. The input 4\n goes into the input buffer, and the value 4 is extracted to variable x.
When std::cin >> y; is encountered, the program will again wait for input. Enter the value 5. The input 5\n goes into the input buffer, and the value 5 is extracted to variable y. Finally, the program will print You entered 4 and 5.
There should be nothing surprising about this run.
Run #2: When std::cin >> x is encountered, the program will wait for input. Enter 4 5. The input 4 5\n goes into the input buffer, but only the 4 is extracted to variable x (extraction stops at the space).
When std::cin >> y is encountered, the program will not wait for input. Instead, the 5 that is still in the input buffer is extracted to variable y. The program then prints You entered 4 and 5.
Note that in run 2, the program didn’t wait for the user to enter additional input when extracting to variable y because there was already prior input in the input buffer that could be used.
*/