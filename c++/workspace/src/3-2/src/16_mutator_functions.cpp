#include <string>
#include <cstring>
#include <iostream>

class Car {
    // TODO: Declare private attributes
    private:
    std::string brand_;
    int horsepower_;
    int weight_;

    // TODO: Declare getter and setter for brand
    public:
    void brand(char*);
    void horsepower(int horsepower);
    void weight(int weight);
    std::string brand() const;
    int horsepower();
    int weight();
};

// Define setters
void Car::brand(char* brand)
{
    brand_ = brand;
}
void Car::horsepower(int horsepower)
{
    horsepower_ = horsepower;
}
void Car::weight(int weight)
{
    weight_ = weight;
}

// Define getters
std::string Car::brand() const
{
    return Car::brand_;
}
int Car::horsepower()
{
    return horsepower_;
}
int Car::weight()
{
    return weight_;
}

// Test in main()
int main()
{
    Car car;
    char brand[] = "Peugeot";
    int horsepower = 6000;
    int weight = 2500;
    car.brand(brand);
    car.horsepower(horsepower);
    car.weight(weight);
    std::cout << "brand : " << car.brand() << std::endl;
    std::cout << "horsepoewr : " << car.horsepower() << std::endl;
    std::cout << "weight : " << car.weight() << "\n";
}