#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::Padding(std::string s, char c)
{
    s.insert(s.begin(), 2 - s.size(), c);
    return s;
}

string Format::ElapsedTime(long seconds)
{ 
    int min = (seconds / 60) % 60;
    int hr = seconds / (60 * 60);
    return std::string(Format::Padding(std::to_string(hr), '0') + ":" +
                        Format::Padding(std::to_string(min), '0') + ":" +
                        Format::Padding(std::to_string(seconds % 60), '0'));
}