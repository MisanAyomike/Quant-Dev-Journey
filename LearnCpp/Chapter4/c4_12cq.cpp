#include <iostream>
#include <string> //for strings
int main()
{
    std::cout<<" Enter a single character: ";
    char ch{};
    std::cin>>ch;
    /*
    std::cout<<" Enter a multiple characters: ";
    std::string ch{};
    std::getline(std::cin, ch); 
    */

    std::cout << "You entered "<<"'"<<ch<<"'"<<", which has ASCII code "<<static_cast<int>(ch)<<".";
    return 0;
}