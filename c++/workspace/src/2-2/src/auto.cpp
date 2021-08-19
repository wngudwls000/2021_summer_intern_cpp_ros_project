#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() {
    auto i = 5;
    auto v_6 = {1, 2, 3};
    cout << "Variables declared and initialized without explicitly stating type!" << "\n";

    // Declare and initialize v using auto here.
    auto v = {7,8,9,10};
    for(auto i : v)
        cout << i << " ";
    cout << "\n";
}