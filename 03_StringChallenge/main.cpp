#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Function to return the reverse of the input string
string get_reverse_string(const string& s) {
    string reversed {s};
    ranges::reverse(reversed); // C++20 reverse using ranges
    return reversed;
}

int main() {
    string user_input {};  // To store the input string
    string pyramid {};     // To build the growing part of the pyramid
    int index {};          // Line index to calculate spaces

    cout << "Enter string to convert it to pyramid : ";
    cin >> user_input;

    const size_t length = user_input.length();  // Length of the input for spacing

    // Loop through each character in the input
    for (const char c: user_input) {
        pyramid += c;  // Append character to the left half of the pyramid

        // Create a string of spaces to center the pyramid
        string spaces_string (length - index, ' ');

        // Combine spaces, pyramid string, and reversed pyramid (excluding first char)
        string temp_string = spaces_string + pyramid + get_reverse_string(pyramid).substr(1);

        // Output the current level of the pyramid
        cout << temp_string << endl;

        index++;  // Move to the next level
    }

    return 0;
}
