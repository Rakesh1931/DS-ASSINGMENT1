#include <iostream>
#include <cstring>
using namespace std;
// for part c
bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}


int main() {
     //(a) Concatenate One String to Another

    char firstText[100] = "Hello ";
    char secondText[] = "rakesh";
    strcat(firstText, secondText);
    cout << "Concatenated String: " << firstText << endl;

     //(b) Reverse a String

       char originalText[] = "Programming";
        int length = strlen(originalText);
     cout << "Reversed String: ";
    for (int reverseIndex = length - 1; reverseIndex >= 0; --reverseIndex) {
        cout << originalText[reverseIndex];
    }
    cout << endl;

    // (c) delete all the vowels from the string.

     char inputPhrase[] = "Beautiful Day";
    char filteredPhrase[100];
    int j = 0;

    for (int i = 0; inputPhrase[i] != '\0'; ++i) {
        if (!isVowel(inputPhrase[i])) {
            filteredPhrase[j++] = inputPhrase[i];
        }
    }
    filteredPhrase[j] = '\0';

    cout << "String without vowels: " << filteredPhrase << endl;

    //(d) Sort Strings in Alphabetical Order

     char wordList[5][20] = {"Banana", "Apple", "Mango", "Cherry", "Peach"};
    char tempWord[20];

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (strcmp(wordList[i], wordList[j]) > 0) {
                strcpy(tempWord, wordList[i]);
                strcpy(wordList[i], wordList[j]);
                strcpy(wordList[j], tempWord);
            }
        }
    }

    cout << "Sorted Words: ";
    for (int k = 0; k < 5; ++k) {
        cout << wordList[k] << " ";
    }
    cout << endl;

    //(e) Convert Character from Uppercase to Lowercase

    char capitalChar = 'G';
    char smallChar = tolower(capitalChar);
    cout << "Lowercase of '" << capitalChar << "' is '" << smallChar << "'" << endl;
  
    return 0;
}