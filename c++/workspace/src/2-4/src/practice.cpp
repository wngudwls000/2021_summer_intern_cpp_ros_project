// // The contents of header_example.h are included in
// // the corresponding .cpp file using quotes:
// #include "practice.h"
// #include <iostream>
// using std::cout;

// void OuterFunction(int i)
// {
//     InnerFunction(i);
// }

// void InnerFunction(int i)
// {
//     cout << "The value of the integer is: " << i << "\n";
// }

// int main()
// {
//     int a = 5;
//     OuterFunction(a);
// }

#include "practice.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;


int IncrementAndComputeVectorSum(vector<int> v)
{
    int total = 0;
    AddOneToEach(v);

    for (auto i: v) {
        total += i;
    }
    return total;
}

void AddOneToEach(vector<int> &v)
{
    // Note that the function passes a reference to v
    // and the for loop below uses references to
    // each item in v. This means the actual
    // ints that v holds will be incremented.
    for (auto& i: v) {
        i++;
    }
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}