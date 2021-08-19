#include <iostream>
#include <cmath>
#include <cassert>
#define PI 3.141592

class LineSegment
{
public:
    double length;
};

class Circle
{
public:
    Circle(LineSegment& radius) : radius_(radius) {}
    double Area()
    {
        return PI * pow(radius_.length,2);
    }
private:
    LineSegment& radius_;
};

// Test in main()
int main()
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}