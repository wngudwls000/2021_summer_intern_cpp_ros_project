// #include <iostream>
// #include <string>
// #include "car.h"
// using std::string;
// using std::cout;
// int main()
// {
//     // Create class instances for each car.
//     Car car_1 = Car("green", 1);
//     Car car_2 = Car("red", 2);
//     Car car_3 = Car("blue", 3);
//     // Increment car_1's position by 1.
//     car_1.IncrementDistance();
//     // Print out the position and color of each car.
//     car_1.PrintCarData();
//     car_2.PrintCarData();
//     car_3.PrintCarData();
// }

#include <iostream>
#include <string>
#include <vector>
#include "car.h"
using std::string;
using std::cout;
using std::vector;
int main() {
    // Create an empty vector of pointers to Cars
    // and a null pointer to a car.
    vector<Car*> car_vect;
    Car* cp = nullptr;

    // The vector of colors for the cars:
    vector<string> colors {"red", "blue", "green"};
    // Create 100 cars with different colors and
    // push pointers to each of those cars into the vector.
    for (int i=0; i < 100; i++) {;
        cp = new Car(colors[i%3], i+1);
        car_vect.push_back(cp);
    }
    // Move each car forward by 1.
    for (Car* cp: car_vect) {
        cp->IncrementDistance();
    }
    // Print data about each car.
    for (Car* cp: car_vect) {
        cp->PrintCarData();
    }
}