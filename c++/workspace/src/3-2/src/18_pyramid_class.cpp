#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

class Pyramid
{
public:
    Pyramid(int length, int width, int height) : length_(length), width_(width), height_(height)
    {
        Validate();
    }
    int length()
    {
        return length_;
    }
    int width()
    {
        return width_;
    }
    int height()
    {
        return height_;
    }
    void length(int length)
    {
        length_ = length;
    }
    void width(int width)
    {
        width_ = width;
    }
    void height(int height)
    {
        height_ = height;
    }
    double volume()
    {
        double volume_ = length_ * width_ * height_ / 3;
        return volume_;
    }
    double area()
    {
        double width_tri_height = sqrt(pow(height_, 2) + pow(width_, 2));
        double length_tri_height = sqrt(pow(height_, 2) + pow(length_, 2));
        double area_of_base = length_ * width_;
        double area_of_width_side = length_ * width_tri_height;
        double area_of_length_side = width_ * length_tri_height;
        double area_ = area_of_base + area_of_length_side + area_of_width_side;
        return area_;
    }
private:
    int length_, width_, height_;
    void Validate()
    {
        if(length_ <= 0 || width_ <= 0 || height_ <- 0)
        {
            throw std::invalid_argument("negative dimension");
        }
    }
};

int main()
{
    Pyramid pyramid(4,5,6);
    cout << pyramid.length() << endl;
    cout << pyramid.width() << endl;
    cout << pyramid.height() << endl;
    cout << pyramid.volume() << endl;
    cout << pyramid.area() << endl;

    assert(pyramid.length() == 4);
    assert(pyramid.width() == 5);
    assert(pyramid.height() == 6);
    assert(pyramid.volume() == 40);

    bool caught{false};
    try {
        Pyramid invalid(-1, 2, 3);
    } catch (...) {
        caught = true;
    }
    assert(caught);
}