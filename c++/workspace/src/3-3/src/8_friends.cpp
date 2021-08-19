#include <iostream>
#include <cassert>
using namespace std;

class Square
{
public:
    Square(int side) : side_(side) {}
private:
    int side_;
    friend class Rectangle;
};

class Rectangle
{
public:
    Rectangle(const Square &a) : width_(a.side_), height_(a.side_) {}
    int Area()
    {
        return width_ * height_;
    }
private:
    int width_;
    int height_;
};

int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16);
}