#include <iostream>
#include <string>
using namespace std;
bool isSubstring(const string& sub, const string& str) {
    return str.find(sub) != string::npos;
}
bool canSplitString(const string& s) {
    int n = s.length();

    // Try all possible splits: i for first cut, j for second cut
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            // Check if any part is a substring of the other two
            if ((isSubstring(A, B) && isSubstring(A, C)) ||
                (isSubstring(B, A) && isSubstring(B, C)) ||
                (isSubstring(C, A) && isSubstring(C, B))) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    string s = "abcababc";
    if (canSplitString(s)) {
        cout << "Yes, the string can be split as required." << endl;
    } else {
        cout << "No, such a split is not possible." << endl;
    }
    return 0;
}