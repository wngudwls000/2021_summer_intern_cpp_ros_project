#include <iostream>
using namespace std;

int main()
{
    int i = 1;

    // Declare a refereence to i.
    int& j = i;
    cout << "The value of j is : " << j << endl;
    
    // Change the value of i.
    i = 5;
    cout <<"The value of i is changed to: " << i << endl;
    cout << "The value of j is now: " << j << "\n";

    // Change the vlaue of the reference.
    // Since reference is just another name for the variable
    // th
    j = 7;
    cout << "The value of j is now : " << j << endl;
    cout << "The value of i is changed to : " << i << endl;
}