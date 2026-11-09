/*Modify the FizzBuzz program you wrote in the previous quiz to add the rule that numbers
divisible by seven should be replaced with “pop”. Run the program for 150 iterations.

In this version, using an if/else chain to explicitly cover every possible combination 
of words will result in a function that is too long. Optimize your function so only
4 if-statements are used: one for each of the non-compound words (“fizz”, “buzz”, “pop”), 
and one for the case where a number is printed.*/

 #include <iostream>
 
 void fizzbuzz(int count)
 {  
    for (int i{1}; i <= count; i++)
    {
        if (i % 3 == 0)
        {
            std::cout<< "fizz";
        }   
        if (i % 5 == 0)
        {
            std::cout<< "buzz";
        }
        if (i % 7 == 0)
        {
            std::cout<< "pop";
        }   
        if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
        {
            std::cout<< i;
        }
        std::cout<<'\n';
    }
 }

 int main ()
 {
    std:: cout<< "Enter a number to be fizzbuzzed: "; 
    int x{};
    std::cin>>x;
    fizzbuzz(x);
    return 0;
 }