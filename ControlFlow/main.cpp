#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <cctype>
#include <set>
#include <numeric>

using namespace std;

// Flag to control program loop
int code_continue {1};

// Multiset to store numbers (ordered with duplicates allowed)
multiset<int> number_list{1,2,3,4,5};

// Function to print all numbers in the list
void print_numbers() {
    cout << "Printing numbers..." << endl;
    cout << "[ ";
    for (int n : number_list)
        cout << n << " ";
    cout << "]\n" << endl;
}

// Function to add a number to the list
void add_number() {
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "Adding number..." << endl;
    number_list.insert(num);
}

// Function to calculate and display the mean of numbers
void mean_numbers() {
    cout << "Calculating mean..." << endl;
    double mean = accumulate(number_list.begin(), number_list.end(), 0.0) / number_list.size();
    cout << "Mean: " << mean << '\n';
}

// Function to display the smallest number
void smallest() {
    cout << "Finding smallest number..." << endl;
    cout << "Smallest: " << *number_list.begin() << '\n';
}

// Function to display the largest number
void largest() {
    cout << "Finding largest number..." << endl;
    cout << "Largest: " << *number_list.rbegin() << '\n';
}

// Function to quit the program
void quit() {
    cout << "Quitting" << endl;
    code_continue = 0;
}

// Menu mapping: input character to description
map <const char, string> menu_map {
    {'p',"Print numbers"}, {'a', "Add Number"}, {'m', "Mean of numbers"},
    {'s', "Smallest Number"}, {'l', "Largest Number"}, {'q', "Quit"}
};

// Function mapping: input character to function pointer
map<char, function<void()>> function_map {
    {'p', print_numbers},
    {'a', add_number},
    {'m', mean_numbers},
    {'s', smallest},
    {'l', largest},
    {'q', quit}
};

// Function to display the menu options
void display_menu(map<const char, string>& m) {
    for (auto it : m) {
        cout << it.first << " : " << it.second << endl;
    }
}

// Get input from user, convert to lowercase, and call corresponding function
void get_user_input() {
    char input {};
    cout << "Enter your choice: ";
    cin >> input;
    input = tolower(input); // case-insensitive input
    if (function_map.count(input))
        function_map.at(input)(); // call matched function
    else
        cout << "Invalid option. " << endl;
}

// Main loop: run until quit option is selected
int main() {
    while (code_continue) {
        display_menu(menu_map);
        get_user_input();
    }

    return 0;
}
