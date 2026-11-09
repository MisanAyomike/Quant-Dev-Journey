#include <iostream>
#include <random> // for std::mt19937
#include <chrono> // for std::chrono

int main()
{
	// Seed our Mersenne Twister using steady_clock
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };

    std::cout<<static_cast<std::mt19937::result_type>(
        std::chrono::steady_clock::now().time_since_epoch().count()
		)<<'\n';

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
/*
The downside of this approach is that if the program is run several times in quick 
succession, the seeds generated for each run won’t be that different, which can impact 
the quality of the random results from a statistical standpoint. For normal programs, 
this doesn’t matter, but for programs that require high quality, independent results, 
this method of seeding may be insufficient.

std::chrono::high_resolution_clock is a popular choice instead of std::chrono::steady_clock. 
std::chrono::high_resolution_clock is the clock that uses the most granular unit of time, but 
it may use the system clock for the current time, which can be changed or rolled back by users.
std::chrono::steady_clock may have a less granular tick time, but is the only clock with a 
guarantee that users cannot adjust it.
*/