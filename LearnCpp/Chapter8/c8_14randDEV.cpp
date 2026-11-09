#include <iostream>
#include <random> // for std::mt19937 and std::random_device

int main()
{
	std::mt19937 mt{ std::random_device{}() };
    std::mt19937 mt2{};
	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}

/*One potential problem with std::random_device: it isn’t required to be non-deterministic, 
meaning it could, on some systems, produce the same sequence every time the program is run, 
which is exactly what we’re trying to avoid. There was a bug in MinGW (fixed in GCC 9.2) that 
would do exactly this, making std::random_device useless.

However, the latest versions of the most popular compilers (GCC/MinGW, Clang, Visual Studio) 
support proper implementations of std::random_device.

Use std::random_device to seed your PRNGs (unless it’s not implemented properly for your target 
compiler/architecture).
*/