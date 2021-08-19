// #include <iostream>
// using std::cout;

// int main() {
// int i = 5;
// int j = 6;
// // Print the memory addresses of i and j
// cout << "The address of i is: " << &i << "\n";
// cout << "The address of j is: " << &j << "\n";
// }

//------------------------------------------------------------------------------

// #include <iostream>
// using std::cout;

// int main()
// {
// int i = 5;
// // A pointer pointer_to_i is declared and initialized to the address of i.
// int* pointer_to_i = &i;
// // Print the memory addresses of i and j
// cout << "The address of i is:" << &i << "\n";
// cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
// }

//------------------------------------------------------------------------------

// #include <iostream>
// using std::cout;

// int main()
// {
// int i = 5;
// // A pointer pointer_to_i is declared and initialized to the address of i.
// int* pointer_to_i = &i;
// // Print the memory addresses of i and j
// cout << "The address of i is: " << &i << "\n";
// cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
// cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
// }

//------------------------------------------------------------------------------

// #include <iostream>
// using std::cout;

// int main() {
// int i = 5;
// // A pointer pointer_to_i is declared and initialized to the address of i.
// int* pointer_to_i = &i;
// // Print the memory addresses of i and j
// cout << "The address of i is:" << &i << "\n";
// cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
// // The value of i is changed.
// i = 7;
// cout << "The new value of the variable i is: " << i << "\n";
// cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
// }

//------------------------------------------------------------------------------
// #include <iostream>
// #include <vector>
// using std::cout;
// using std::vector;

// int main() {
//     // Vector v is declared and initialized to {1, 2, 3}
//     vector<int> v {1, 2, 3};
//     // Declare and initialize a pointer to the address of v here:

//     // The following loops over each int a in the vector v and prints.
//     // Note that this uses a "range-based" for loop:
//     // https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-for-range
//     for (int a: v) {
//         cout << a << "\n";
//     }

//     // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
    
// }

//------------------------------------------------------------------------------

// #include <iostream>
// using std::cout;

// void AddOne(int* j)
// {
//     // Dereference the pointer and increment the int being pointed to.
//     (*j)++;
// }

// int main()
// {
//     int i = 1;
//     cout << "The value of i is: " << i << "\n";
//     // Declare a pointer to i:
//     int* pi = &i;
//     AddOne(pi);
//     cout << "The value of i is now: " << i << "\n";
// }

//------------------------------------------------------------------------------

#include <iostream>
using std::cout;

int* AddOne(int& j)
{
    // Increment the referenced int and return the
    // address of j.
    j++;
    return &j;
}

int main()
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";
    // Declare a pointer and initialize to the value
    // returned by AddOne:
    int* my_pointer = AddOne(i);
    cout << "The value of i is now: " << i << "\n";
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";
}

//------------------------------------------------------------------------------