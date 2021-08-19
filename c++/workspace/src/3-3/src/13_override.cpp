#include <iostream>
#include <cmath>
#include <cassert>

#define PI 3.141592

class VehicleModel
{
    virtual void Move(double v, double theta) = 0;

};

class ParticleModel :public VehicleModel
{
public:
    void Move(double v, double phi) override
    {
        theta += phi;
        x += v * cos(theta);
        y += v * sin(theta);
    }
    double x = 0.0;
    double y = 0.0;
    double theta = 0.0;
};

class BicycleModel : public ParticleModel
{
public:
    BicycleModel() : length(0.0) {}
    void Move(double v, double phi) override
    {
        theta += v / length * tan(phi);
        x += v * cos(theta);
        y += v * sin(theta); 
    }
private:
    double length;
};

int main() {
    // Test function overriding
    ParticleModel particle;
    BicycleModel bicycle;
    particle.Move(10, PI / 9);
    bicycle.Move(10, PI / 9);
    assert(particle.x != bicycle.x);
    assert(particle.y != bicycle.y);
    assert(particle.theta != bicycle.theta);
}