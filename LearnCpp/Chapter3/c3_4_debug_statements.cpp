#include <iostream>
//#define ENABLE_DEBUG is optional would have tp remove the ifndef and endif too to keep cerr permanently
//#define ENABLE_DEBUG // comment out to disable debugging

int getValue()
{
#ifdef ENABLE_DEBUG
std::cerr << "getValue() called\n";  //temporary debugging statements.
#endif
	return 4;
}

int main()
{
#ifdef ENABLE_DEBUG
std::cerr << "main() called\n"; // temporary debugging statements.
#endif
    std::cout << getValue() << '\n'; // added parenthesis here

    return 0;
}
