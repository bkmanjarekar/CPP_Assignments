#include <iostream>
#include <string>
using namespace std;


// Includes uppercase, lowercase, and digits
const string ORIGINAL   = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
const string SUBSTITUTE = "$(W2d,Di|jl6]MozS9[hYZ)1}'{B4JxNmgaCrV#O<K7`QFp +tHw!.G8cP/e@f3";


string encrypt(const string& input) {
    string result;
    for (char c : input) {
        size_t index = ORIGINAL.find(c);
        result += (index != string::npos) ? SUBSTITUTE[index] : c;
    }
    return result;
}


string decrypt(const string& input) {
    string result;
    for (char c : input) {
        size_t index = SUBSTITUTE.find(c);
        result += (index != string::npos) ? ORIGINAL[index] : c;
    }
    return result;
}


int main() {
    string plain;
    cout << "Enter plain text to encrypt and decrypt: ";
    getline(cin, plain);
    string encrypted = encrypt(plain);
    string decrypted = decrypt(encrypted);

    cout << "Original : " << plain << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}

