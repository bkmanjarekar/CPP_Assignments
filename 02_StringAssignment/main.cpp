#include <iostream>
#include <string>
using namespace std;

// Character sets for substitution cipher
// ORIGINAL contains allowed characters: uppercase, lowercase, digits, and space
// SUBSTITUTE contains the mapped characters in shuffled order (must match ORIGINAL in length)
const string ORIGINAL   = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
const string SUBSTITUTE = "$(W2d,Di|jl6]MozS9[hYZ)1}'{B4JxNmgaCrV#O<K7`QFp +tHw!.G8cP/e@f3";

// Encrypts the input string by substituting each character using the SUBSTITUTE string
string encrypt(const string& input) {
    string result;
    for (char c : input) {
        // Find index of character in ORIGINAL
        size_t index = ORIGINAL.find(c);
        // Append mapped character from SUBSTITUTE or leave unchanged if not found
        result += (index != string::npos) ? SUBSTITUTE[index] : c;
    }
    return result;
}

// Decrypts the input string by reversing the substitution using the ORIGINAL string
string decrypt(const string& input) {
    string result;
    for (char c : input) {
        // Find index of character in SUBSTITUTE
        size_t index = SUBSTITUTE.find(c);
        // Append mapped character from ORIGINAL or leave unchanged if not found
        result += (index != string::npos) ? ORIGINAL[index] : c;
    }
    return result;
}

int main() {
    string plain;
    cout << "Enter plain text to encrypt and decrypt: ";
    getline(cin, plain);  // Read entire line as input

    // Perform encryption and decryption
    string encrypted = encrypt(plain);
    string decrypted = decrypt(encrypted);

    // Output results
    cout << "Original : " << plain << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
