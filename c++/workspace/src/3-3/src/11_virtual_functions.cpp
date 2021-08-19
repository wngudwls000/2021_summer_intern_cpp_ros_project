#include <cmath>
#include <cassert>
#include <iostream>
#define PI 3.141592654

class Shape
{
public:
    Shape() {}
    virtual double Area() = 0;
    virtual double Perimeter() = 0;
};

class Rectangle
{
public:
    Rectangle(int width, int height) : width_(width), height_(height) {}
    virtual int Area() { return (width_ * height_); }
    virtual int Perimeter() { return (width_ + height_) * 2; }
private:
    int width_;
    int height_;
};

class Circle
{
public:
    Circle(float radius) : radius_(radius) {}
    virtual float Area() { return PI * pow(radius_,2); }
    virtual float Perimeter() { return 2 * PI * radius_; }
private:
    float radius_;
};

int main() {
    double epsilon = 0.1; // useful for floating point equality
    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);
    // Test rectangle
    Rectangle rectangle(10, 6);
    assert(rectangle.Perimeter() == 32);
    assert(rectangle.Area() == 60);
}


