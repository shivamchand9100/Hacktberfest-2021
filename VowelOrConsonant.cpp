#include <iostream>
using namespace std;

int main() {
    char c;
    bool isLCVowel, isUCVowel;

    cout << "Enter an alphabet: ";
    cin >> c;
    isLCVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    isUCVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (!isalpha(c))
      printf("It's a non-alphabetic character.");
    else if (isLCVowel || isUCVowel)
        cout << c << " is a vowel.";
    else
        cout << c << " is a consonant.";

    return 0;
