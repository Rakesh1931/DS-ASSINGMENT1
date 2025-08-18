#include <iostream>
#include <string>
using namespace std;
bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length()) return false;
    int count[26] = {0};

    // Count characters from str1
    for (char ch : str1) {
        count[ch - 'a']++;
    }
    // Subtract characters from str2
    for (char ch : str2) {
        count[ch - 'a']--;
    }
    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

int main() {
    string str1 = "listen";
    string str2 = "silent";

    if (areAnagrams(str1, str2)) {
        cout << "Yes, the strings are anagrams." << endl;
    } else {
        cout << "No, the strings are not anagrams." << endl;
    }
    return 0;
}