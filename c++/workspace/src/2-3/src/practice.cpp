// #include <iostream>
// using std::cout;


// int MultiplyByTwo(int i) {
//     i = 2*i;
//     return i;
// }

// int main() {
//     int a = 5;
//     cout << "The int a equals: " << a << "\n";
//     int b = MultiplyByTwo(a);
//     cout << "The int b equals: " << b << "\n";
//     cout << "The int a still equals: " << a << "\n";
// }

//-------------------------------------------------------------------

// #include <iostream>
// using std::cout;


// int MultiplyByTwo(int &i) {
//     i = 2*i;
//     return i;
// }

// int main() {
//     int a = 5;
//     cout << "The int a equals: " << a << "\n";
//     int b = MultiplyByTwo(a);
//     cout << "The int b equals: " << b << "\n";
//     cout << "The int a now equals: " << a << "\n";
// }

//-------------------------------------------------------------------

// #include <iostream>
// #include <string>
// using std::cout;
// using std::string;


// void DoubleString(string &reference) {
//     // Concatentate the string with a space and itself.
//     reference = reference + " " + reference;
// }

// int main() {
//     string s = "Hello";
//     cout << "The string s is: " << s << "\n";
//     DoubleString(s);
//     cout << "The string s is now: " << s << "\n";
// }

//-------------------------------------------------------------------

// #include <iostream>

// int main()
// {
//     int i;
//     std::cout << "Enter an integer value for i: ";
//     std::cin >> i;
//     const int j = i * 2; // "j can only be evaluated at run time."
//     // "But I promise not to change it after it is initialized."
//     constexpr int k = 3;
//     // "k, in contrast, can be evaluated at compile time."
//     std::cout << "j = " << j << "\n";
//     std::cout << "k = " << k << "\n";
// }

//-------------------------------------------------------------------

#include <iostream>
#include <vector>

int sum(const std::vector<int> &v)
{
    int sum = 0;
    for(int i : v)
    sum += i;
    return sum;
}

int main()
{
    std::vector<int> v {0, 1, 2, 3, 4};
    std::cout << sum(v) << "\n";
}