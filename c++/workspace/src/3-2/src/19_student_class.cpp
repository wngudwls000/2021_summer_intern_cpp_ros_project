#include <iostream>
#include <cassert>

using namespace std;

class Student
{
public:
    Student(string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa) 
    {
        Validate();
    }
    void Name(string name)
    {
        name_ = name;
        Validate();
    }
    void Grade(int grade)
    {
        grade_ = grade;
        Validate();
    }
    void GPA(float gpa)
    {
        gpa_ = gpa;
        Validate();
    }
    string Name()
    {
        return name_;
    }
    int Grade()
    {
        return grade_;
    }
    float GPA()
    {
        return gpa_;
    }
private:
    string name_;
    int grade_;
    float gpa_; //grade_point_average
    void Validate()
    {
        if(Grade() < 0 || Grade() > 12 || GPA() < 0.0 || GPA() > 4.0)
        {
            throw std::invalid_argument("argument out of bounds");
        }
    }
};

int main()
{
    Student david("David Silver", 10, 4.0);

    cout << david.Name() << endl;
    cout << david.Grade() << endl;
    cout << david.GPA() << endl;

    assert(david.Name() == "David Silver");
    assert(david.Grade() == 10);
    assert(david.GPA() == 4.0);

    bool caught{false};
    try {
        david.Grade(20);
    }
    catch(...) {
        caught = true;
    }
    assert(caught);
}