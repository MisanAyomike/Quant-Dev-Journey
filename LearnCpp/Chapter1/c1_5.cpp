#include <iostream>
int main()
{
    std::cout << "Hi!";
    std::cout << "My name is Misan.";

    std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line
    std::cout << "My name is Alex." << std::endl;

    int x{ 5 };
    std::cout << "x is equal to: " << x << '\n'; // single quoted (by itself) (conventional)
    std::cout << "Yep." << "\n";                 // double quoted (by itself) (unconventional but okay)
    std::cout << "And that's all, folks!\n";     // between double quotes in existing text (conventional)
    std::cout << ' \n'; //  single quoted character newline with space creates literal 8202
    std::cout << '!'; 
    std::cout << '.\n'; // single quoted character period with newline creates literal 11786
    std::cout << "!!";
    std::cout << '/n'; // single quoted character forward slash with n creates literal 12142
    return 0;
}