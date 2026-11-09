#include <iostream>
#include <string>

int main()
{
    std::string fname {};
    std::cout<< "Enter your full name: ";
    std::getline(std::cin, fname); // note: no std::ws here'

    int age{};
    std::cout<< "Enter your age: ";
    std::cin>> age;
    //std::cout<< "Your age + length of name is: "<< fname.length() + age; adds the space

    int space{};
    for (int i = 0; i < fname.length(); i++)
    {
        if (fname[i] == ' ')
        {
            space++;
        }
    }

    std::cout<< "Your age + length of name is: "<< fname.length() + age - space;

    return 0;
}