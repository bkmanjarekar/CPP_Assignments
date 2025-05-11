#include <iostream>
#include <vector>

using namespace std;

// Denominations in cents: dollar = 100, quarter = 25, etc.
vector<int> currency {100, 25, 10, 5, 1};
// Corresponding names for the denominations
vector<string> currency_names {"dollar", "quarter", "dime", "nickel", "penny"};
// Vector to store the count of each denomination
vector<int> count (5, 0);

// Function to calculate change based on the input amount in cents
void find_out_change(int cents) {
    // Iterate over each denomination
    for(unsigned int i = 0; i < currency.size(); i++) {
        // Determine how many coins/notes of current denomination can be used
        if(const int div = static_cast<int>(static_cast<float>(cents) / static_cast<float>(currency[i])); div >= 1) {
            count[i] = static_cast<int>(div); // Store the count
            cents -= currency[i] * div;       // Subtract the used amount from cents
        }
    }
}

// Function to display the result (number of each coin/note)
void show_change() {
    // Loop through each denomination name and print corresponding count
    for(unsigned int i = 0; i < currency_names.size(); i++) {
        cout << currency_names[i] << " : "  << count[i] << endl;
    }
}

int main() {
    int cents {0}; // Variable to store user input
    cout << "Enter an amount in cents : ";
    cin >> cents; // Read input

    find_out_change(cents); // Calculate the change
    show_change();          // Display the result

    return 0;
}
