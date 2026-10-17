#include <iostream>
using namespace std;

int main()
{
    int x{};
    cout << "Enter an integer: ";
    cin >> x;

    int y{};
    cout << "Enter another integer: ";
    cin >> y;
    cout << x << " + " << y << " is " << x + y << ".\n";
    cout << x << " - " << y << " is " << x - y << ".\n"; 
    return 0;
}