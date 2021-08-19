#include <iostream>
#include <cassert>
#include <cmath>

#define PI 3.141592

using namespace std;

class Sphere
{
public:
    Sphere(int radius) : radius_(radius), volume_(PI * pow(radius_,3) * 4 / 3)
    {
        if(radius <= 0)
        {
            throw std::invalid_argument("radius must be positive");
        }
    }
    int Radius()
    {
        return radius_;
    }
    float Volume()
    {
        return volume_;
    }
    void Radius(int radius)
    {
        if(radius <= 0)
        {
            throw std::invalid_argument("radius must be positive");
        }
        radius_ = radius;
        volume_ = PI * pow(radius_,3) * 4 / 3;
    }
private:
    int radius_;
    float volume_;

};

int main(void) {
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);

    sphere.Radius(3);
    assert(sphere.Radius() == 3);
    assert(abs(sphere.Volume() - 113.1) < 1);
    
    bool caught{false};
    try {
        sphere.Radius(-1);
    } catch (...) {
        caught = true;
    }
    assert(caught);
}