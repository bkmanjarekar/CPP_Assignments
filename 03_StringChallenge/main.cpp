#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


string get_reverse_string(const string& s) {
    string reversed {s};

    ranges::reverse(reversed);

    return reversed;
}


int main() {
    // Your code here
    string user_input {};
    string pyramid {};
    int index {};

    cout << "Enter string to convert it to pyramid : ";
    cin >> user_input;

    const size_t length = user_input.length();

    for (const char c: user_input) {
        pyramid += c;
        string spaces_string (length-index, ' ');
        string temp_string = spaces_string + pyramid + get_reverse_string(pyramid).substr(1);
        cout << temp_string << endl;
        index++;
    }

    return 0;
}

