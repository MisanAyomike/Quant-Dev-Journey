/*Write a short program to simulate a ball being dropped off of a tower. To start, the user
 should be asked for the height of the tower in meters. Assume normal gravity (9.8 m/s2), 
 and that the ball has no initial velocity (the ball is not moving to start). 
 Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 
 5 seconds. The ball should not go underneath the ground (height 0).

Use a function to calculate the height of the ball after x seconds. The function can calculate 
how far the ball has fallen after x seconds using the following formula: distance 
fallen = gravity_constant * x_seconds2 / 2*/

#include <iostream>

double calcHeightOfBall(double towerHeight, int seconds)
{
    const double gravity{9.8};
    const double distanceFallen{(gravity * seconds*seconds) / 2};
    double ballHeight{towerHeight - distanceFallen};
    return ballHeight;
}

int main()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin>> towerHeight;
    int seconds{};

    if(calcHeightOfBall(towerHeight, seconds)>0 && seconds == 0)
    {
        std::cout<<"At "<<seconds<<" seconds, the ball is at "<< calcHeightOfBall(towerHeight, seconds) << " meters high."<<'\n';
        seconds++;
    }
    if(calcHeightOfBall(towerHeight, seconds)>0 && seconds ==1)
    {
        std::cout<<"At "<<seconds<<" seconds, the ball is at "<< calcHeightOfBall(towerHeight, seconds) << " meters high."<<'\n';
        seconds++;
    }
    if(calcHeightOfBall(towerHeight, seconds)>0 && seconds ==2)
    {
        std::cout<<"At "<<seconds<<" seconds, the ball is at "<< calcHeightOfBall(towerHeight, seconds) << " meters high."<<'\n';
        seconds++;
    }
    if(calcHeightOfBall(towerHeight, seconds)>0 && seconds ==3)
    {
        std::cout<<"At "<<seconds<<" seconds, the ball is at "<< calcHeightOfBall(towerHeight, seconds) << " meters high."<<'\n';
        seconds++;
    }
    if(calcHeightOfBall(towerHeight, seconds)>0 && seconds ==4)
    {
        std::cout<<"At "<<seconds<<" seconds, the ball is at "<< calcHeightOfBall(towerHeight, seconds) << " meters high."<<'\n';
        seconds++;
    }
    if(calcHeightOfBall(towerHeight, seconds)>0 && seconds ==5)
    {
        std::cout<<"At "<<seconds<<" seconds, the ball is at "<< calcHeightOfBall(towerHeight, seconds) << " meters high."<<'\n';
        seconds++;
    }
    else
    {
        std::cout<<"At "<<seconds<<" seconds, the ball is on the ground.";
    }
    return 0;
}