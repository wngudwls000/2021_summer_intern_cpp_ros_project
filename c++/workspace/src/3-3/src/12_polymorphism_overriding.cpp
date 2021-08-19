#include <assert.h>
#include <string>
class Animal {
public:
 virtual std::string Talk() const = 0;
};
class Dog : public Animal {
 public:
 virtual std::string Talk() const {return "Woof";}

};
// TODO: Declare a class Dog that inherits from Animal
int main() {
 Dog dog;
 assert(dog.Talk() == "Woof");
}