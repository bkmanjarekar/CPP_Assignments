#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <cctype>
#include <set>
#include <numeric>

using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int code_continue {1};
multiset<int> number_list{1,2,3,4,5};

void print_numbers() {
    cout << "Printing numbers..." << endl;
    cout << "[ ";
    for (int n : number_list)
        cout << n << " ";
    cout << "]\n" << endl;
}
void add_number() {
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "Adding number..." << endl;
    number_list.insert(num);
}
void mean_numbers() {
    cout << "Calculating mean..." << endl;
    double mean = accumulate(number_list.begin(), number_list.end(), 0.0) / number_list.size();
    cout << "Mean: " << mean << '\n';
}
void smallest() {
    cout << "Finding smallest number..." << endl;
    cout << "Smallest: " << *number_list.begin() << '\n';
}
void largest() {
    cout << "Finding largest number..." << endl;
    cout << "Largest: " << *number_list.rbegin() << '\n';
}
void quit() {
    cout << "Quitting" << endl;
    code_continue = 0;
}

map <const char, string> menu_map {{'p',"Print numbers"}, {'a', "Add Number"}, {'m', "Mean of numbers"},
        {'s', "Smallest Number"}, {'l', "Largest Number"}, {'q', "Quit"}};

map<char, function<void()>> function_map {
            {'p', print_numbers},
            {'a', add_number},
            {'m', mean_numbers},
            {'s', smallest},
            {'l', largest},
            {'q', quit}
};

void display_menu(map<const char, string>& m) {
    for (auto it : m) {
        cout << it.first << " : " << it.second << endl;
    }
}

void get_user_input() {
    char input {};
    cout << "Enter your choice: ";
    cin >> input;
    input = tolower(input);
    if (function_map.count(input))
        function_map.at(input)();
    else
        cout << "Invalid option. " << endl;
}

int main() {
    while (code_continue) {
        display_menu(menu_map);
        get_user_input();
    }

    return 0;
}