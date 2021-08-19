#include <iostream>
using namespace std;


class Human {};
class Dog {};
class Cat {};

void hello()
{
    cout<<"hello world!"<<endl;
}
void hello(Human human)
{
    cout<<"hello human!"<<endl;
}
void hello(Dog dog)
{
    cout<<"hello dog!"<<endl;
}
void hello(Cat cat)
{
    cout<<"hello cat!"<<endl;
}
int main()
{
    hello();
    hello(Human());
    hello(Dog());
    hello(Cat());
}