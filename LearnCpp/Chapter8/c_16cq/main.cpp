#include "Random.h"
#include <iostream>
using namespace std;
int main()
{
    char repeat{};
    do
    {
        cout<<"Let's play a guessing game. \n";
        cout<<"Enter a min number you want me to create the guess from: ";
        int min{};
        cin>> min;
        cout<<"Enter a max number you want me to create the guess from: ";
        int max{};
        cin>> max;
        cout<<"Enter how many tries you want: ";
        int tries{};
        cin>> tries;
        int rand_num {Random::get(min, max)};
        cout <<"I'm thinking of a number between "<< min<<" and "<<max<<". You have "<<tries<<" tries to guess what it is."<<'\n';
        int count{1}, guess{};
        do
        {
            cout << "Guess #"<< count << ": ";
            cin >>guess;
            if (guess > rand_num)
                cout<<"Your guess is too high."<<'\n';
            else if (guess < rand_num)
                cout<<"Your guess is too low."<<'\n';
            count++;
        }
        while (count != tries+1 && guess != rand_num);
        if (guess == rand_num)
            cout<<"Yay, you're correct!!!"<<'\n';
        else
            cout<<"Sorry, you lose. The correct number was "<< rand_num<<". \n";
        do 
        {
            cout<<"Would you like to play again (y/n)? ";
            cin>> repeat;
        }
        while (repeat != 'n' && repeat != 'y');
        
    }
    while (repeat == 'y');
    return 0;

}


