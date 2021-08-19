#include <iostream>

using namespace std;

class Animal
{
public:
    string color;
    string name;
    int age;
private:
};

class Snake : public Animal
{
public:
    float length;
    void MakeSound()
    {
        cout << "belebele" << endl;
    }
private:
};

class Cat : public Animal
{
public:
    float height;
    void MakeSound()
    {
        cout << "niaaaaong" << endl;
    }
private:
};

int main()
{
    Snake snake;
    Cat cat;
    snake.MakeSound();
    cat.MakeSound();
}