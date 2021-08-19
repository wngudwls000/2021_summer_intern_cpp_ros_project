#include <iostream>
#include <string>
#include <cassert>
class Animal {
public:
 double age;
};

class Pet {
public:
 std::string name;
};

// Dog derives from *both* Animal and Pet
class Dog : public Animal, public Pet {
public:
 std::string breed;
};

class Cat : public Animal, public Pet{
 public:
 std::string color;
};

int main()
{
 Animal animal;
 Pet pet;
 Dog dog;
 Cat cat;
 cat.color = "black";
 cat.age = 10;
 cat.name = "Max";
 assert(cat.color == "black");
 assert(cat.age == 10);
 assert(cat.name == "Max");
}